### 解题思路
方法一：穷举法
1,循环遍历，识别各种可能

### 代码

```c
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
```