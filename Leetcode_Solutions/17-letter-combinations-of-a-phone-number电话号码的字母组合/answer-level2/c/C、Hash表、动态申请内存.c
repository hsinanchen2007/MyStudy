### 解题思路
 1，建立Hash表，对应数字和字符间的关系，方便使用
 2，增加函数判断输入字符串是否有效，并且输出有多少种字符组合
 3，申请内存，先申请字符串指针数组，后逐个申请字符数组，注意结束字符
 4，做循环填写组合结果

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hash
{
    char    cNum;
    int     iLen;
    char    cChar[5];
} HASH;

HASH    Hash[10] = {
    '0',  0, "",
    '1',  3, "!@#",
    '2',  3, "abc",
    '3',  3, "def",
    '4',  3, "ghi",
    '5',  3, "jkl",
    '6',  3, "mno",
    '7',  4, "pqrs",
    '8',  3, "tuv",
    '9',  4, "wxyz",
};

// 判断输入字符串是否有效,并且输出有多少种字母组合
int JudgeInput(char* pInput, int* pRangeNum)
{
    int     iLen    = 0;
    int     i       = 0;
    int     iRange  = 1;

    while(pInput[i] != '\0')
    {
//        printf("[1] i=%d, %d, %d \n", i, pInput[i], pInput[i] - '0');
        if ((pInput[i] >= '2') && (pInput[i] <= '9'))
        {
            iRange *= Hash[pInput[i] - '0'].iLen;
            
            iLen += 1;
            i += 1;
        }
        else
        {
            iLen = 0;
            break;
        }
    }

    *pRangeNum = iRange;
    return iLen;
}

char ** letterCombinations(char * digits, int* returnSize){
    char    **ppRet      = NULL;
    int     iRangeNum    = 0;           // 输入字符串能表示的字符组合数量
    int     numsSize     = 0;           // 输入字符串数量
    int     i            = 0;
    int     j            = 0;
    int     k            = 0;
    int     interval     = 0;

    numsSize = JudgeInput(digits, &iRangeNum);
    if (numsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

//    printf("[2] numsSize=%d iRangeNum=%d \n", numsSize, iRangeNum);
    // 理解为 创建一个 char* 指针 数组，每个指针还需要 malloc numsSize个char大小保存结果
    ppRet = (char **)malloc(sizeof(char *) * iRangeNum);
    *returnSize = iRangeNum;
    interval = iRangeNum;

    for (i = 0; i < numsSize; i++)
    {
        k = Hash[digits[i] - '0'].iLen;
        interval /= k;                      // 每个数字的间隔，表示后面数字有多少种组合，该数字则需要重复出现多少遍
        
        for (j = 0; j < iRangeNum; j++)
        {
            if (i == 0)
            {
                ppRet[j] = (char *)malloc(sizeof(char) * (numsSize + 1));
                ppRet[j][numsSize] = '\0';
            }

            //通过Hash 表找到对应的字符  （位置下标 / 数字间隔）% 数字对应的字符个数
            ppRet[j][i] = Hash[digits[i] - '0'].cChar[(j / interval) % (k)];
//            printf("[3] i=%d j=%d k=%d ppRet=%c\n", i, j, k, ppRet[j][i]);
        }
    }
    return ppRet;
}
```