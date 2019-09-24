## Libraries:
1. [PyBind11]( https://github.com/pybind/pybind11 )
    - Call C++ code from Python and vise versa
	- Clone repository in /lib folder, along side /src
```
	mkdir lib
	cd lib
	git clone https://github.com/pybind/pybind11.git
```	

## Building:
Navigate the terminal to be inside Python-Calling-CPP-Test

```
	mkdir Build
	cd Build
	cmake ..
	make
```	

## Running the test:
Navigate to Python-Calling-CPP-Test/build/
and run the following command:
```
	./example
```	