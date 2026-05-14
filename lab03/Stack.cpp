#include <iostream>
#include <string.h>
using namespace std;

#define ERROR   -1
#define CORRECT  1
#define MAXSTACKSIZE 100

// 1、堆栈的定义
typedef struct SqStack {
    char base[MAXSTACKSIZE];  // 栈底指针，也是栈的基址
    char *top;                // 栈顶指针
} SqStack;

SqStack MBStack;

// 2、初始化堆栈
int InitStack(SqStack &S)
{
    if (S.base == NULL) return(ERROR);
    S.top = S.base;           // 初始化堆栈(清空堆栈)
    return(CORRECT);
}

// 3、进栈
int Push(SqStack &S, char e)  // 向栈中放入数据[进栈]
{
    if ((S.top - S.base) >= MAXSTACKSIZE) return(ERROR);
    *S.top++ = e;
    return(CORRECT);
}

// 4、出栈
int Pop(SqStack &S, char &e)  // 从栈中取数据[出栈]
{
    if (S.top <= S.base) return(ERROR);
    e = *--S.top;
    return(CORRECT);
}

// 5、判断栈空
int StackEmpty(SqStack &S)
{
    if (S.top <= S.base) return(ERROR);
    return(CORRECT);
}

// 6、括号匹配
int MatchBracket(SqStack &S, char *BracketString)  // 判断括号是否匹配
{
    int i;
    char C, sC;

    InitStack(S);                              // 清空堆栈
    for (i=0; i<strlen(BracketString); i++) {
        C = BracketString[i];
        if ((C == '(') || (C == '[') || (C == '{')) Push(S, C);
        if ((C == ')') || (C == ']') || (C == '}')) {
            if (StackEmpty(S) == ERROR) return(-2);  // 右括号多于左括号
            Pop(S, sC);
            if ((C == ')') && (sC != '(')) return(-1);  // 左右括号配对次序不正确
            if ((C == ']') && (sC != '[')) return(-1);
            if ((C == '}') && (sC != '{')) return(-1);
        }
    }
    if (StackEmpty(S) != ERROR) return(-3);  // 左括号多于右括号
    return(0);                               // 左右括号匹配正确
}

// 7、主程序
int main()
{
    int i, SampleNum;
    char BracketString[MAXSTACKSIZE];

    cin >> SampleNum;
    for (i=0; i<SampleNum; i++) {
        cin >> BracketString;
        cout << MatchBracket(MBStack, BracketString) << endl;
    }
    return 0;
}