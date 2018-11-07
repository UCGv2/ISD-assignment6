/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: Vector.h
 */
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>
#ifndef ASSIGNMENT6_SOLUTION_VECTOR_H
#define ASSIGNMENT6_SOLUTION_VECTOR_H

struct VectIterator {
    double* iterator;
};

/**
 * Template class Vector made to represent a mathemetical vector and perform all rhe vector
 * arithmetic you can manage
 * @tparam T size of the vector
 */
template <uint32_t T> class Vector {
public:
    //    typedef double* iterator;



    /**
     * default ctor
     */
    Vector();

    /** Ctor
     *
     * @param src
     */
    Vector(const double src[]);

    /**Copy ctor
     *
     * @param rhs
     */
    Vector(const Vector& rhs);

    /** assignment operator
     *
     * @param rhs vector we're copying
     * @return updated reference to this
     */
    Vector& operator=(const Vector& rhs);

    /** provides a string representation of the the vector
     *
     * @return the contents of the Vector between '[' and ']'
     */
    std::string toString() const;

    /** Functions as an iterator to the first element
     *
     * @return a pointer to the first value of the vector
     */
    double* begin() const noexcept;

    /** Functions as an iterator to the point past the last element
     *
     * @return a pointer to the space past the last value of the vector
     */
    double* end() const noexcept;

    /** non const subscript operator
     *
     * @param index index of Vector
     * @return value at index in mValues
     */
    double& operator[](const uint32_t& index);

    /** const subscript operator
     *
     * @param index index of Vector
     * @return value at index in mValues
     */
    const double& operator[](uint32_t index) const;

    /** equality operator
     *
     * @param rhs other vector for comparison
     * @return whether the values of two vectors are close enough to be considered equal
     */
    bool operator==(const Vector& rhs) const;

    /** inequality operator
     *
     * @param rhs other vector for comparison
     * @return whether the values of two vectors are not close enough to be considered equal
     */
    bool operator!=(const Vector& rhs) const;
    /** addition operator
     *
     * @param rhs other vector
     * @return return a vector with the sums
     */
    Vector operator+(const Vector& rhs) const;

    /**
     *
     * @param rhs
     * @return
     */
    Vector operator-(const Vector& rhs) const;


    /**
     *
     * @return
     */
    Vector operator-() const;

    /**
     *
     * @param rhs
     * @return
     */
    double operator*(const Vector& rhs) const;

    /**
     *
     * @param num
     * @return
     */
    Vector operator*(const double& num) const;

    /**
     *
     * @param rhs
     * @return
     */
    Vector& operator*=(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector& operator+=(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector& operator-=(const Vector& rhs);
    /**
     *
     * @param rhs
     * @return
     */
    Vector operator/(const Vector& rhs) const;

    /**
     *
     * @param rhs
     * @return
     */
    Vector& operator/=(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector add(const Vector& rhs) const;

    /**
     *
     * @return
     */
    Vector invert();

    /**
     *
     * @param num
     * @return
     */
    Vector scale(const double& num);

    /**
     *
     * @param rhs
     * @return
     */
    double dot(const Vector& rhs) const;

    /**
     *
     * @param rhs
     * @return
     */
    Vector& norm(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector& normalize(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector& normSq(const Vector& rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Vector& cross(const Vector& rhs);

    /** Scalar multiplication operator overloaded for Vector support
     *
     * @tparam U size of vector
     * @param num number to multipy
     * @param rhs source vector
     * @return a Vector containing the result of the operation
     */
    template <uint32_t U> friend Vector<U> operator*(const double& num, const Vector<U>& rhs);
    /** Scalar multiplication operator overloaded for Vector support
     *
     * @tparam U size of vector
     * @param num number to multipy
     * @param rhs source vector
     * @return a Vector containing the result of the operation
     */
    template <uint32_t U> friend Vector<U>& operator*=(const double& num, Vector<U>& rhs);
    /** Scalar multiplication operator overloaded for Vector support
     *
     * @tparam U size of vector
     * @param num number to multipy
     * @param rhs source vector
     * @return a Vector containing the result of the operation
     */
    template <uint32_t U> friend Vector<U>& operator*=(Vector<U>& rhs, const double& num);

    /** Scalar division operator overloaded for Vector support
     *
     * @tparam U size of vector
     * @param num number to divide with
     * @param rhs source vector
     * @return a Vector containing the result of the operation
     */
    template <uint32_t U> friend Vector<U> operator/(Vector<U>& rhs, const double& num);

    /** Scalar division operator overloaded for Vector support
     *
     * @tparam U size of vector
     * @param num number to divide with
     * @param rhs source vector
     * @return a Vector containing the result of the operation
     */
    template <uint32_t U> friend Vector<U>& operator/=(Vector<U>& rhs, const double& num);


private:

    /**
     * an array representing our Vector
     */
    double mValues[T] ={0};
};

template <uint32_t U> Vector<U> operator*(const double& num, const Vector<U>& rhs)
{
    Vector<U> copy(rhs);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return (double)x * (double)num; });
    return copy;
}

template <uint32_t U> Vector<U>& operator*=(const double& num, Vector<U>& rhs)
{
    Vector<U> copy(rhs);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return (double)x * (double)num; });
    std::swap(rhs, copy);

    return rhs;
}
template <uint32_t U> Vector<U>& operator*=(Vector<U>& rhs, const double& num)
{
    Vector<U> copy(rhs);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return (double)x * (double)num; });
    std::swap(rhs, copy);

    return rhs;
}
template <uint32_t U> Vector<U> operator/(Vector<U>& rhs, const double& num)
{
    Vector<U> copy(rhs);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return (double)x / (double)num; });
    return copy;
}
template <uint32_t U> Vector<U>& operator/=(Vector<U>& rhs, const double& num)
{
    Vector<U> copy(rhs);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return (double)x / (double)num; });
    std::swap(rhs, copy);
    return rhs;
}

#include "../src/Vector.cpp"

#endif // ASSIGNMENT6_SOLUTION_VECTOR_H
