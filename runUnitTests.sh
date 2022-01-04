INCLUDE_PATH=/path/to/folder
# the above path is where the folder containing all the support files for this framework is located

if [ $# -lt 2 ]; then
    printf "BEFORE FIRST USE YOU MUST SPECIFY THE INCLUDE_PATH VARIABLE IN THE SCRIPT\nMAKING AN ALIAS TO RUN THIS SCRIPT FROM ANYWHERE IS ALSO RECOMMENDED. CHECK THE SCRIPT FOR HOW TO DO THESE THINGS\n\nYou need to supply 2 arguments to this script.\nUsage: ./runUnitTests.sh [name of unit test file (can have a path in front)] [name of file being tested (no path in front)]\nExample: ./runUnitTests.sh [path]tests.cpp myFunctions.c\n\nNote: you need to be in the directory of the header file of the file with functions to be tested for this to work.\n(Generally there can't be any paths before the file with functions to test).\nThe folders above the current folder should also not have spaces in their names.\n"
    exit 1
fi

read -p "Would you like to make the test plan? (y/n) " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Nn]$ ]]; then
    gcc ${INCLUDE_PATH}makeTestPlan.c -o makeTestPlan
    ./makeTestPlan $1 # argument 1 for unit test file name
fi

read -p "Would you like to run the test plan? (y/n) " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Nn]$ ]]; then
    echo "Compiling test plan"
    g++ -I${INCLUDE_PATH} -I${PWD} -w -fpermissive -c testPlan.cpp -o testPlan
    echo "Compiling unit tests"
    g++ -I${INCLUDE_PATH} -I${PWD} -w -fpermissive -c $1 -o unitTests
    echo "Compiling file to be tested"
    gcc -I${PWD} -c $2 -o DUT # argument 2 for name of file to test
    echo "Compiling extra functions"
    g++ -I${INCLUDE_PATH} -c -Wno-pointer-arith ${INCLUDE_PATH}Assert.cpp -o Assert # would be good to eventually update Assert.cpp so that the error isn't thrown and I can remove the tag to ignore the warning
    echo "Linking"
    g++ testPlan unitTests DUT Assert -o tests
    echo "Running tests"
    ./tests
    echo "Remove all generated files"
    rm testPlan* unitTests DUT Assert tests makeTestPlan
fi

echo "Done!"

# example usage: ./runUnitTests.sh unittest1.cpp fileToTest.c
# Alias to run the script from anywhere (put in .bashrc): alias runUnitTests='/path/to/script/runUnitTests.sh' 
