**思路：**
使用数组保存输入数字每一位的值，然后检查是否越界，如果没有越界就用数组中的值反着计算反转后的结果。


**代码：**
#include <math.h>

#define MAXLEN 10


/* 判断给定数字是否越界 */
char judgeOverFolw(char *pNum)
{
    char u8IsOverFlow = 0; /* 返回值，0表示未越界 */
    char u8MaxNum[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
    char u8i = 0;


    for (u8i = 0; u8i < MAXLEN - 1; u8i++)
    {
        if (u8MaxNum[u8i] < pNum[u8i])
        {
            return u8i + 1;
        }
        else if (u8MaxNum[u8i] > pNum[u8i])
        {
            return 0;
        }
    }

    return 0; /* 该分支理论上不会走到 */
}

int reverse(int x){
    char u8Flag = 0; /* 记录源数字的符号, 0表示正数，1表示负数 */
    unsigned int  s32Input = 0;
    char u8SrcNum[10] = { 0 }; /* 记录源数字的每一位的值 */
    char u8BitNum = 0; /* 源数字的有效位数 */
    int s32XReverse = 0;
    char u8i = 0;
    char u8j = 0;

    if (-2147483648 == x)
    {
        return 0;
    }

    /* 记录输入数字符号，并将其转换成正数 */
    if (0 > x)
    {
        u8Flag = 1;
        s32Input = -x;
    }
    else
    {
        u8Flag = 0;
        s32Input = x;
    }

    /* 获取输入数字的每一位的值 */
    for (u8i = 0; u8i < 10; u8i++)
    {
        if (0 == s32Input)
        {
            break;
        }
        u8SrcNum[u8i] = s32Input % 10;
        s32Input /= 10;
        u8BitNum++;
    }

    /* 对有效位数进行保护 */
    if (u8BitNum > MAXLEN)
    {
        u8BitNum = MAXLEN;
    }

    /* 在输入数字位数等于最大值时校验其翻转是否越界 */
    if (MAXLEN == u8BitNum)
    {
        if (0 != judgeOverFolw(u8SrcNum))
        {
            return 0;
        }
    }

    /* 计算翻转后的结果 */
    for (u8i = 0; u8i < u8BitNum; u8i++)
    {
        s32XReverse += (int)(u8SrcNum[u8i] * pow(10, u8BitNum - u8i - 1));
    }

    s32XReverse *= (int)pow(-1, u8Flag);

    return s32XReverse;
}