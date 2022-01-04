#include <iostream>
#include <string.h>
#include "CppUnitTest.h"

// Using this page as a reference for what I should implement: https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019#general_asserts

namespace Assert
{
    void AreEqual(long thing1, long thing2) // passing pointers here might give the incorrect output
    {
        std::cout << ((thing1 == thing2) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void AreEqual(char* thing1, char* thing2) // hopefully doesn't interfere with pointer comparisons
    {
        std::cout << ((strncmp(thing1, thing2, strlen(thing1)) == 0) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void AreNotEqual(long thing1, long thing2)
    {
        std::cout << ((thing1 != thing2) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void AreNotEqual(char* thing1, char* thing2) // hopefully doesn't interfere with pointer comparisons
    {
        std::cout << ((strncmp(thing1, thing2, strlen(thing1)) != 0) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void AreSame(void* thing1, void* thing2) // implicit casting here might not work
    {
        std::cout << ((thing1 == thing2) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void AreNotSame(void* thing1, void* thing2)
    {
        std::cout << ((thing1 != thing2) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void IsNull(long thing)
    {
        std::cout << ((thing == NULL) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void IsNotNull(long thing)
    {
        std::cout << ((thing != NULL) ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void IsTrue(int thing)
    {
        std::cout << (thing ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void IsFalse(int thing)
    {
        std::cout << (!thing ? "\tTest passed" : "\tTest failed") << std::endl;
    }
    void Fail()
    {
        std::cout << "\tTest failed" << std::endl;
    }
}
