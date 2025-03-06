#include <iostream>

class Matrix
{
private:
    const bool is_equal_size(const Matrix &obj) const
    {
        if (_cols != obj._cols && _rows != obj._rows)
        {
            return false;
        }
        return true;
    }
    int _rows, _cols; // Rows and columns

public:
    double **_matrix; // Pointer to the memory where the matrix is allocated

    Matrix() : Matrix(_rows, _cols) {};

    Matrix(int rows, int cols)
    {

        _rows = rows;

        _cols = cols;

        _matrix = new double *[rows]();

        for (int i = 0; i < rows; ++i)
        {
            _matrix[i] = new double[cols]();
        }
    }

    Matrix(const Matrix &copy)
    {
        *this = copy;
    };

    int Get_cols() const
    {
        return _cols;
    }

    int Get_rows() const
    {
        return _rows;
    }

    Matrix(Matrix &&obj)
    {
        for (int i = 0; i < _rows; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _rows = obj._rows;
        _cols = obj._cols;
        _matrix = obj._matrix;
        obj._rows = 0;
        obj._cols = 0;
        obj._matrix = nullptr;
    };

    bool eq_matrix(const Matrix &obj)
    {
        if (!is_equal_size(obj))
        {
            return false;
        }
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                if (_matrix[i][j] != obj._matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    };

    void operator=(const Matrix &copy)
    {
        for (int i = 0; i < _rows; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;

        _rows = copy._rows;

        _cols = copy._cols;

        _matrix = new double *[_rows];

        for (int i = 0; i < _rows; ++i)
        {
            _matrix[i] = new double[_cols];
        }

        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                _matrix[i][j] = copy._matrix[i][j];
            }
        }
    }
    Matrix operator+(const Matrix &obj)
    {
        Matrix C = *this;
        C.sum_matrix(obj);
        return C;
    }

    Matrix operator-(const Matrix &obj)
    {
        Matrix C = *this;
        C.sub_matrix(obj);
        return C;
    }

    Matrix operator*(const Matrix &obj)
    {
        Matrix C = *this;
        C.mul_matrix(obj);
        return C;
    }

    void operator+=(const Matrix &obj)
    {
        sum_matrix(obj);
    }

    void operator-=(const Matrix &obj)
    {
        sub_matrix(obj);
    }

    void operator*=(const Matrix &obj)
    {
        mul_matrix(obj);
    }

    void operator*=(const double obj)
    {
        mul_number(obj);
    }

    void fill_matrix() const
    {
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                std::cin >> _matrix[i][j];
            }
        }
    }

    double &operator()(int i, int j)
    { // a._matrix[0][0] = 5; -> a(0,0) = 5;
        if (i > _rows || j > _cols)
        { // ����������
            return _matrix[_rows - 1][_cols - 1];
        }
        return _matrix[i][j];
    }

    void mul_number(const double num)
    {
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                _matrix[i][j] *= num;
            }
        }
    }

    void sum_matrix(const Matrix &obj)
    {
        if (!is_equal_size(obj))
        {
            return;
        }
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                _matrix[i][j] += obj._matrix[i][j];
            }
        }
    }

    void sub_matrix(const Matrix &obj)
    {
        if (!is_equal_size(obj))
        {
            return;
        }
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                _matrix[i][j] -= obj._matrix[i][j];
            }
        }
    }

    void mul_matrix(const Matrix &obj)
    {
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                for (int k = 0; k < _cols; ++k)
                {
                    _matrix[i][j] += obj._matrix[i][k] * _matrix[k][j];
                }
            }
        }
    }

    Matrix transpose() const
    {
        Matrix matrix(_cols, _rows);
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                matrix._matrix[j][i] = _matrix[i][j];
            }
        }
        return matrix;
    }

    void Print() const
    {
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Matrix()
    {
        if (_matrix != nullptr)
        {

            for (int i = 0; i < _rows; ++i)
            {
                delete[] _matrix[i];
            }
            delete[] _matrix;
        }
    }; // Destructor
};