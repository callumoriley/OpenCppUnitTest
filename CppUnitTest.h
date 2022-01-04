#define TEST_CLASS(className) class className
#define TEST_METHOD(methodName) static void methodName(void)

// This is called CppUnitTest because that's the name of the actual header file for the test framework that I'm trying to replicate

namespace Assert
{
    void AreEqual(long thing1, long thing2);
    void AreEqual(char* thing1, char* thing2);
    void AreNotEqual(long thing1, long thing2);
    void AreNotEqual(char* thing1, char* thing2);
    void AreSame(void* thing1, void* thing2);
    void AreNotSame(void* thing1, void* thing2);
    void IsNull(long thing);
    void IsNotNull(long thing);
    void IsTrue(int thing);
    void IsFalse(int thing);
    void Fail();
}