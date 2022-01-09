#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define DEFAULT_TEST_NAME "unittest1.cpp"

int main(int argc, char *argv[])
{
    FILE* sourceFilePointer;
    FILE* writeFilePointer;
    
    char currLine[MAX_LINE_LEN];
    char writeLine[MAX_LINE_LEN];
    char currClassName[MAX_LINE_LEN];
    char currMethodName[MAX_LINE_LEN];
    char namespaceName[MAX_LINE_LEN];

    char currObjectName = 'a' - 1;

    sourceFilePointer = fopen((argc >= 2) ? argv[1] : DEFAULT_TEST_NAME, "r");
    writeFilePointer = fopen("testPlan.cpp", "w");
    
    if (sourceFilePointer == NULL || writeFilePointer == NULL) return 1;

    fprintf(writeFilePointer, "#include <iostream>\n#include \"%s\"\n\nint main(void)\n{\n", (argc >= 2) ? argv[1] : DEFAULT_TEST_NAME);

    while (fgets(currLine, MAX_LINE_LEN, sourceFilePointer))
    {
        if (strstr(currLine, "namespace"))
        {
            sscanf(currLine, "%*s %s", namespaceName);
        }
        else if (strstr(currLine, "TEST_CLASS"))
        {
            sscanf(currLine, "%*[^(](%[^)]", currClassName);
            currObjectName++;
            fprintf(writeFilePointer, "\t%s::%s %c;\n", namespaceName, currClassName, currObjectName);
            fprintf(writeFilePointer, "\tputs(\"%s\");\n", currClassName);
        }
        else if (strstr(currLine, "TEST_METHOD"))
        {
            sscanf(currLine, "%*[^(](%[^)]", currMethodName);
            fprintf(writeFilePointer, "\tputs(\"%s\");\n\t%c.%s();\n", currMethodName, currObjectName, currMethodName);
        }
    }
    fputs("\n\treturn 0;\n}\n",writeFilePointer);
    return 0;
}
