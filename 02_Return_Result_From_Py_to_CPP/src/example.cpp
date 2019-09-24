#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;


int main(int argc, char const *argv[])
{
    py::scoped_interpreter guard{};
    
    // This will hold the values from the python script after it's been executed
    auto locals = py::dict();

    py::eval_file("example.py", py::globals(), locals);
    
    std::string resultFromPython = locals["result"].cast<std::string>();

    std::cout << "value of 'result' variable from python: " << resultFromPython << '\n';

    return 0;
}

