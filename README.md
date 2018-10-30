# CS 3251: Intermediate Software Design
## Programming Assignment 6

## Overview

This assignment will give you a chance to further explore some important C++ features: templates, operator overloading and functors/lambdas. You are to implement a Vector class (not an STL Vector, but a mathematical Vector) that supports basic mathematical operations. It would be too boring to only implement three dimensional vectors; therefore, the assignment requires templates so that a Vector class can be instantiated for arbitrary sizes.

Unlike some of the previous assignments, no header files will be provided. It is your responsibility to analyze the sample (by no means comprehensive) driver file and infer the necessary class public interface, which will let you practice software development in a more realistic manner. After all, some clients do not even know what a header file is, but they do know how they want to use your class.

If you are clever about your design, you should be able to reuse a lot of your methods when defining new ones. Also, please note that since we are “passing” the dimension of the vector as a template parameter, no dynamic memory allocation is required. A good example for you to reference is the StackParam2 example from the Templates lecture from earlier in the semester. 

## Necessary Details

* Iterators - You will need to make your Vector class iterable and to provide iterators.  Use the STL standard _begin()_ and _end()_ methods.  Consider implementing the iterators as one of your first capabilities.

* toString() – You need to implement a toString() method that returns a human-readable string representation of your vector in order to simplify the testing of your program. Note that if you do not get this method right, many of the tests will fail. Thus, this method should be one of the first methods implemented and tested.

* Functors/Lambdas – You are **not allowed to use any explicit looping constructs** in your code. This will force you to use the STL algorithms together with user-defined function objects (functors) or Lamdba expressions.  You can not use std::for_each, but other STL algorithms are allowed.  You are also **not to use the functors provided by STL**, nor the vector operations provided in `<numeric>`. You may use functors and lambdas that you write yourself; functors may inherit from std::binary_function, but this is not necessary.  The reference solution uses only three user-defined functors and one custom iterator - it kind of looks like a back_inserter.

* Operator overloading – We want to make the use of our class as natural as possible. Therefore, you will be asked to overload several mathematical operators. You should ensure that commutative operators remain commutative in your class.

* Template specialization – Most of the methods you are required to write apply to vectors of all dimensions. Cross products, however, only hold meaning in three (and seven) dimensions. This “weird” behavior will give you the opportunity to explore a feature called template specialization (see the Template lecture). Refer to the test file for the desired results.

* Directory & File Structure - Make sure you continue to follow the directory structure used in all previous assignments.  Put your headers into an ```include``` directory and all source files into a ```src``` directory.  ```Vector``` will be a template class, so split into .h and .cpp files as we have been.  Separate out any helper functions (if you use functors, for example) into a file called ```include/helpers.h```.  You do not have to split helper functions into .h and .cpp files.

* Exception safety - All methods should be at least strongly exception safe.  Make sure to use ```noexcept``` if the method can not throw an exception.

* Documentation – Since you are designing this class from scratch, it is imperative that you comment your code well. Your intentions of what the method is to do, the required inputs, outputs, etc. must be clear and the documentation must follow the course coding standard.  Please use JavaDocs standard formatting, per the course style guidelines.

* Be aware, there are negative compilation tests (i.e. failure to compile tests) at the bottom of the testing file.  Uncommenting either of these blocks of code should result in a compilation failure.  This will be graded manually and is not exercised by Travis.

Note: It is unlikely that you have done an assignment like this before. Please start early and ask questions if you are unsure of anything. Notice that your design will impact the grading of the Structure and Insightful Programming sections of the rubric.

The testing driver and CMakeLists.txt for the assignment are given to you. For a review of mathematical vectors and operations used you can read [Paul's notes on vectors](http://tutorial.math.lamar.edu/Classes/CalcII/VectorsIntro.aspx).

All students have the same assignment and there are no extra tasks for graduate students on this assignment.

### REMINDERS:

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files unless explicitly directed otherwise!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with recent versions of `clang` and `gcc` and run successfully with Travis CI.
  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository.