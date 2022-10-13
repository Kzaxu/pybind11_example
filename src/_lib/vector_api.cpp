#include <pybind11/stl_bind.h>
#include <pybind11/pybind11.h>
#include <vector>
#include "vector_api.h"

using namespace std;
namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(vector<int>);


void push_num(vector<int>& vec, int num) {
    vec.push_back(num);
}

PYBIND11_MODULE(vector_api, m) {
    py::bind_vector<vector<int>>(m, "VectorInt");
    m.def("push_num", &push_num);
}
