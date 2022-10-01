import numpy as np


def read_matrix(path: str):
    matrix = []
    with open(path, 'r') as fp:
        for i in fp.readlines():
            row = i.split()
            row = list(map(float, row))
            matrix.append(row)
    del matrix[0]
    return matrix


if __name__ == "__main__":
    matrix1 = np.array(read_matrix("C:/Users/Stepan/source/repos/ParaProg/ParaProg/matrix1.txt"))
    matrix2 = np.array(read_matrix("C:/Users/Stepan/source/repos/ParaProg/ParaProg/matrix2.txt"))
    matrix_res = np.dot(matrix1, matrix2)
    print("Matrix mul by Py:\n ", matrix_res)
    matrix_c_res = np.array(read_matrix("C:/Users/Stepan/source/repos/ParaProg/ParaProg/mres.txt"))
    print("Matrix mul by C:\n ", matrix_c_res)
    print(np.array_equal(matrix_res, matrix_c_res))


