#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>


using namespace Eigen;
typedef Matrix<double, Dynamic, Dynamic, RowMajor> MatrixXdR;


template<typename T>
void set_first_row(Ref<Matrix<T, Dynamic, Dynamic, RowMajor>> mat, T d) {
    if (mat.rows() < 1) {
        return ;
    }
    int cols = mat.cols();
    for (int i = 0; i < cols; ++i) {
        mat(0, i) = d;
    }
}


PYBIND11_MODULE(eigen_api, m) {
    m.def("set_first_row_d", &set_first_row<double>);
    m.def("set_first_row_i", &set_first_row<int>);
}