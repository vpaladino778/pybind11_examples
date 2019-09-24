#include <pybind11/embed.h>
#include <pybind11/stl_bind.h>
#include <pybind11/embed.h>
#include <iostream>

// [1] Must be placed at the top of the file, directly after #includes
PYBIND11_MAKE_OPAQUE(std::vector<int>);

namespace py = pybind11;
using namespace py::literals;

class ExampleClass
{
    public:
    std::vector<int> DataVector;

}

/* [2] Specifies the binary module. This can then be imported
 *  in the python script
 */
PYBIND11_EMBEDDED_MODULE(examplemodule, m) 
{
    py::class_<ExampleClass>(m,"ExampleClass")
        .def(py::init<>())
        .def_readwrite("contents", &ExampleClass::DataVector);

}
int main(int argc, char const *argv[])
{
    py::scoped_interpreter guard{};

    // Instantiate vector and fill with data
    std::vector<int> exampleData;
    exampleData.push_back(1);

    auto module = py::module::import("examplemodule");
    
    // Pass exampleData object to python script
    auto locals = py::dict(
        "example_data"_a=py::cast(exampleData, py::return_value_policy::reference), // by reference
        **module.attr("__dict__"));

    std::cout << "exampleData[0] value C++: " << exampleData[0] << '\n';

    py::eval_file("example.py", py::globals(), locals);
    
    std::cout << "exampleData[0] value C++ after running example.py: " << exampleData[0] << '\n';

    return 0;
}

/** Pybind11 Relevant documentation links:
 * [1] https://pybind11.readthedocs.io/en/stable/advanced/cast/stl.html#binding-stl-containers
 * [2] https://pybind11.readthedocs.io/en/stable/advanced/embedding.html#adding-embedded-modules
 * 
 */

