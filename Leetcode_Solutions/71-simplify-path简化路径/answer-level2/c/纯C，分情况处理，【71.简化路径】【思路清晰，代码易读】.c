### 解题思路
//方法一：分情况处理

### 代码

```c
//方法一：分情况处理
#define     STATE_0     0       // "/"
#define     STATE_1     1       // "./"
#define     STATE_2     2       // "../"
#define     STATE_3     3       // "abc"/"
#define     STATE_4     4       // 其他

char * simplifyPath(char * path){
    int     i       = 0;
    int     j       = 0;
    int     iLen    = strlen(path);
    char*   pRet    = NULL;
    int     iLpos   = 0;
    bool    bLFlag  = false;
    int     iPos    = 0;
    int     iState  = STATE_0;

    pRet = (char*)malloc(sizeof(char) * (iLen + 1));
    memset(&pRet[0], 0x00, sizeof(char) * (iLen + 1));
    pRet[0] = '/';
    iLpos = 1;
    iPos = 1;

    for (i = 0; i < iLen; i++)
    {
        for (j = i; j < iLen; j++)
        {
            if (path[j] == '/')
            {
                //滑窗结束
                break;
            }
            else if (path[j] == '.')
            {
                if (iState == STATE_0)
                {
                    iState = STATE_1;
                }
                else if (iState == STATE_1)
                {
                    iState = STATE_2;
                }
                else
                {
                    iState = STATE_4;
                }
            }
            else
            {
                iState = STATE_3;
            }
        }

//        printf("[1][iLen=%d][i=%d][j=%d][ipos=%d][iState=%d]\n", iLen, i, j, iPos, iState);
        switch(iState)
        {
            case STATE_0 :
                //不处理
                break;
            case STATE_1 :
                //不处理
                break;
            case STATE_2 :
                //退回到上一个目录
//                printf("[2][i=%d][j=%d][ipos=%d][iLpos=%d][iState=%d][%s]\n", i, j, iPos, iLpos, iState, pRet);
                for (iLpos = iPos; iLpos >= 1; iLpos--)
                {
                    if (pRet[iLpos] == '/')
                    {
                        if (!bLFlag)
                        {
                            bLFlag = true;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                bLFlag = false;
                iPos = iLpos + 1;
                memset(&pRet[iPos], 0x00, sizeof(char) * (iLen - iPos));
                break;
            case STATE_3 :
            case STATE_4 :
                //将有效目录放入返回目录中
                memcpy(&pRet[iPos], &path[i], sizeof(char) * (j - i + 1));
                iLpos = iPos;
                iPos += j - i + 1;
                break;
            default:
                break;
        }
        iState = STATE_0;
        i = j;
    }

//    printf("[3][i=%d][j=%d][ipos=%d][iState=%d][%s]\n", i, j, iPos, iState, pRet);

    if (iPos > 1)
    {
        pRet[iPos - 1] = '\0';
    }
    return pRet;
}
```