/** Name: Christopher Glenn
 *  vunetid: glennca1
 *  email: christopher.a.glenn@vanderbilt.edu
 *  Honor code: I have neither given nor received unauthorized aid on this assignment.
 *  file: Vector.cpp
 */
#include <Vector.h>
// if Def?
// safety: remember to throw except from the constructors

template <uint32_t T> Vector<T>::Vector()
{}
// could just use default value initialization on this to make default ctor obsolete
template <uint32_t T> Vector<T>::Vector(const double src[T])
{
    double mValueCopy[T];
    std::copy_n(src, T, mValueCopy);
    std::swap(mValues, mValueCopy);
}

template <uint32_t T> Vector<T>::Vector(const Vector<T>& rhs)
{
    double mValueCopy[T] = { 0 };
    std::copy_n(rhs.mValues, T, mValueCopy);
    std::swap(mValues, mValueCopy);
}

template <uint32_t T> Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if (*this != rhs) {
        Vector<T> copy(rhs);
        std::swap(mValues, copy.mValues);
    }
    return *this;
}

 template <uint32_t T>
 std::string Vector<T>::toString() const
{
    Vector<T> copy(*this);
    std::string out = "";

    std::transform(copy.begin(), copy.end(), copy.begin(),[copy, &out](double x){out = out +
    std::to_string(x) + " ";}); return out;
}

template <uint32_t T> double* Vector<T>::begin() const noexcept
{
    return const_cast<double*>(mValues);
}
template <uint32_t T> double* Vector<T>::end() const noexcept
{
    return const_cast<double*>(mValues + T);
}

template <uint32_t T> double& Vector<T>::operator[](const uint32_t& index)
{
    return const_cast<double&>(static_cast<const Vector<T>*>(this)->operator[](index));
}
template <uint32_t T> const double& Vector<T>::operator[](uint32_t index) const
{
    return mValues[index];
}
// check that the difference is smaller than 10 x 10^-9 for equality
template <uint32_t T> bool Vector<T>::operator==(const Vector<T>& rhs) const
{
    Vector<T> copy(*this);
    std::transform(copy.begin(), copy.end(), rhs.begin(), copy.begin(),
        [copy, rhs](double x, double y) { return (double)abs(x - y); });
    double closeEnough = 10 * pow(10, -9);

    return std::all_of(
        copy.begin(), copy.end(), [copy, closeEnough](double x) { return x < closeEnough; });
}
template <uint32_t T> bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
    return !(operator==(rhs));
}
template <uint32_t T> Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const
{
    Vector<T> copy(*this);
    Vector<T> copy2(rhs);
    std::transform(copy.begin(), copy.end(), copy2.begin(), copy.begin(),
        [copy, rhs](double x, double y) -> double { return x + y; });
    return copy;
}
template <uint32_t T> Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const
{
    Vector<T> copy(*this);
    Vector<T> copy2(rhs);
    std::transform(copy.begin(), copy.end(), copy2.begin(), copy.begin(),
        [copy, rhs](double x, double y) -> double { return x - y; });

    return copy;
}
template <uint32_t T> Vector<T> Vector<T>::operator-() const
{
    Vector<T> copy(*this);
    std::transform(
        copy.begin(), copy.end(), copy.begin(), [copy](double x) -> double { return x * (-1); });
    return copy;
}
template <uint32_t T> double Vector<T>::operator*(const Vector<T>& rhs) const
{
    return dot(rhs);
}
template <uint32_t T> Vector<T> Vector<T>::operator*(const double& num) const
{
    Vector<T> copy(*this);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return x * (double)num; });
    return copy;
}

template <uint32_t T> Vector<T>& Vector<T>::operator*=(const Vector& rhs)
{
    std::transform(begin(), end(), rhs.begin(), begin(),
        [this, rhs](double x, double y) -> double { return x * y; });
    return *this;
}
template <uint32_t T> Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
    std::transform(begin(), end(), rhs.begin(), begin(),
        [this, rhs](double x, double y) -> double { return x + y; });
    return *this;
}
template <uint32_t T> Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs)
{
    std::transform(begin(), end(), rhs.begin(), begin(),
        [this, rhs](double x, double y) -> double { return x - y; });
    return *this;
}
template <uint32_t T> Vector<T> Vector<T>::operator/(const Vector<T>& rhs) const
{
    std::transform(begin(), end(), rhs.begin(), begin(),
        [this, rhs](double x, double y) -> double { return x / y; });
    return *this;
}
template <uint32_t T> Vector<T>& Vector<T>::operator/=(const Vector<T>& rhs)
{
    std::transform(begin(), end(), rhs.begin(), begin(),
        [this, rhs](double x, double y) -> double { return (double)x / (double)y; });
    return *this;
}
template <uint32_t T> Vector<T> Vector<T>::add(const Vector<T>& rhs) const
{
    Vector<T> copy(rhs);
    std::transform(copy.begin(), copy.end(), rhs.begin(), copy.begin(),
        [copy, rhs](double x, double y) -> double { return (double)x + (double)y; });
    return copy;
}
template <uint32_t T> Vector<T> Vector<T>::invert()
{
    Vector<T> copy(*this);
    std::transform(
        copy.begin(), copy.end(), copy.begin(), [copy](double x) -> double { return x * (-1); });
    return copy;
}
template <uint32_t T> Vector<T> Vector<T>::scale(const double& num)
{
    Vector<T> copy(*this);
    std::transform(copy.begin(), copy.end(), copy.begin(),
        [copy, num](double x) -> double { return x * (double)num; });
    return copy;
}
 template <uint32_t T>
 double Vector<T>::dot(const Vector& rhs) const
{
    Vector<T> copy(*this);
    Vector<T> copy2(rhs);
    Vector<T> mult = copy * copy2;
    double ret;
    std::transform(mult.begin(), mult.end(), mult.begin(),
            [mult, &ret](double x){ ret= ret+x; return ret; });
    return mult[T-1];
}
// template <uint32_t T>
// Vector<T>& Vector<T>::norm(const Vector& rhs)
//{}
// template <uint32_t T>
// Vector<T>& Vector<T>::normalize(const Vector& rhs)
//{}
// template <uint32_t T>
// Vector<T>& Vector<T>::normSq(const Vector& rhs)
//{}
// template <uint32_t T>
// Vector<T>& Vector<T>::cross(const Vector& rhs)
//{}