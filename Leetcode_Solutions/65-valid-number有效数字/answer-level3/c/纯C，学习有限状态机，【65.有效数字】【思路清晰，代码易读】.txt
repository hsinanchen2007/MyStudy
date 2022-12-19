### 解题思路
方法二：有限状态机
1,画出状态转移图
2,根据状态转移图，建立状态列表

### 代码

```c
//方法二：有限状态机
//1,画出状态转移图
//2,根据状态转移图，建立状态列表

#define     STEP_BLANK      0
#define     STEP_SYMBOL     1
#define     STEP_DIGIT      2
#define     STEP_DOT        3
#define     STEP_E          4
#define     STEP_OTHER      5

int endTable[9] = {0, 0, 0, 1, 0, 1, 1, 0, 1};
int stateTable[9][6] = {
    { 0,  1,  6,  2, -1, -1},
    {-1, -1,  6,  2, -1, -1},
    {-1, -1,  3, -1, -1, -1},
    { 8, -1,  3, -1,  4, -1},
    {-1,  7,  5, -1, -1, -1},
    { 8, -1,  5, -1, -1, -1},
    { 8, -1,  6,  3,  4, -1},
    {-1, -1,  5, -1, -1, -1},
    { 8, -1, -1, -1, -1, -1}
};

//函数一：转换字符
int switchChar(char c){
    int     iStep   = 0;

    if (c == ' ')
    {
        iStep = STEP_BLANK;
    }
    else if ((c == '+') || (c == '-'))
    {
        iStep = STEP_SYMBOL;
    }
    else if ((c >= '0') && (c <= '9'))
    {
        iStep = STEP_DIGIT;
    }
    else if (c == '.')
    {
        iStep = STEP_DOT;
    }
    else if (c == 'e')
    {
        iStep = STEP_E;
    }
    else
    {
        iStep = STEP_OTHER;
    }
    return iStep;
}

//函数二：状态机
int stateMachine(int iState, int iStep){
    int     iRet      = 0;

    iRet = stateTable[iState][iStep];

    return iRet;
}

bool isNumber(char * s){
    int     i           = 0;
    int     iStep       = 0;
    int     iState      = 0;
    bool    bFlag       = true;

    while (s[i] != '\0')
    {
        iStep = switchChar(s[i]);

        iState = stateMachine(iState, iStep);
        if (iState == -1)
        {
            bFlag = false;
            break;
        }
        i += 1;
    }

    if ((iState != -1) && (endTable[iState] != 1))
    {
        bFlag = false;
    }

    return bFlag;
}




/*
//方法一：穷举法
//1,循环遍历，识别各种可能
bool isNumber(char * s){
    int     i           = 0;
    bool    bRet        = true;
    bool    bDFlag      = false;
    bool    bEFlag      = false;
    bool    bAFlag      = false;
    bool    bRFlag      = false;
    bool    bPFlag      = false;
    bool    bFirst      = true;

    while (s[i] != '\0')
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            bDFlag = true;
            bFirst = false;
            i += 1;
        }
        else if (s[i] == 'e')
        {
            if ((bEFlag) || (bDFlag == false))
            {
                bRet = false;
                break;
            }
            if (((s[i + 1] < '0') || (s[i + 1] > '9')) && (s[i + 1] != '+') && (s[i + 1] != '-'))
            {
                bRet = false;
                break;
            }
            i += 1;
            bEFlag = true;
            bFirst = false;
        }
        else if ((s[i] == '+') || (s[i] == '-'))
        {
            if ((bFirst != true) && (bEFlag != true))
            {
                bRet = false;
                break;
            }
            if ((bEFlag == true) && (s[i - 1] != 'e'))
            {
                bRet = false;
                break;
            }
            if ((bEFlag == true) && (s[i - 1] == 'e') && ((s[i + 1] < '0') || (s[i + 1] > '9')))
            {
                bRet = false;
                break;
            }
            i += 1;
            bAFlag = true;
            bFirst = false;
        }
        else if (s[i] == '.')
        {
            if (bEFlag || bPFlag)
            {
                bRet = false;
                break;
            }

            if ((s[i + 1] == '\0') && (bDFlag == false))
            {
                bRet = false;
                break;
            }

            i += 1;
            bPFlag = true;
            bFirst = false;
        }
        else if (s[i] == ' ')
        {
            if ((bFirst == true) && (s[i + 1] != '\0'))
            {
                i += 1;
                continue;
            }

            if (((s[i + 1] != ' ') && (s[i + 1] != '\0')) || (bDFlag == false))
            {
                bRet = false;
                break;
            }
            i += 1;
        }
        else
        {
            bRet = false;
            break;
        }
    }
    return bRet;
}
*/
```