### 解题思路
1，开辟足够大的空间作为栈使用
2，入栈操作，当输入为 ({[ 时入栈
3，出栈操作，当输入为 ]}) 和栈顶元素匹配则出栈，不匹配则结束
4，当栈中元素归0时说明匹配成功，否则匹配失败

### 代码

```c
bool isValid(char * s){
    char    cTmpBuf[2048*2]     = {0};
    int     iTopPoint       = 0;
    int     i               = 0;
    bool    bRet            = true;

    while(s[i] != '\0')
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            iTopPoint += 1;
            cTmpBuf[iTopPoint] = s[i];
            
//            printf("[1] i=%d, s=%c, point=%d\n", i, s[i], iTopPoint);
        }
        else
        {
            if (((s[i] == ')') && (cTmpBuf[iTopPoint] == '('))
                || ((s[i] == '}') && (cTmpBuf[iTopPoint] == '{')) 
                || (s[i] == ']') && (cTmpBuf[iTopPoint] == '['))
            {
//                printf("[2] i=%d, s=%c - %c, point=%d\n", i, s[i], cTmpBuf[iTopPoint], iTopPoint);
                iTopPoint -= 1;
            }
            else
            {
//                printf("[3] i=%d, s=%c - %c, point=%d\n", i, s[i], cTmpBuf[iTopPoint], iTopPoint);
                bRet = false;
                break;
            }
        }
        i += 1;
    }

    if (iTopPoint != 0)
    {
        bRet = false;
    }
    return bRet;
}
```