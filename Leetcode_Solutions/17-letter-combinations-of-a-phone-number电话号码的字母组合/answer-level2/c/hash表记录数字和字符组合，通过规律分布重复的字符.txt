### 解题思路
// 随着输入字母的增多，字母的组合越来越多，单对于单列来说，该列对应一个数字的字母
// 变化是有规律的，字符一直在循环出现
// 连续出现的次数等于后面每级字符个数的乘积
// 拿"23"来说，2中的a处于第一级别，下一级别有3个字母，所以连续重复出现3次 
// 这个地方通过树状图会比较好理解，a需要重复出现3次，若再加一级数字4，则a重复出现3*3 = 9次
/***************************
    a       b       c
    |       |       |
    d e f   d e f   d e f

****************************/

### 代码

```c
typedef struct tagHAST_ST
{
    char    cNum;
    int     iLen;
    char    cChar[5];
} HASH;

HASH  Hash[10] = 
{
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
int JudgeInput(char* pInput, int* pRowNum, int *pColNum)
{
    int     i       = 0;
    int     colNum  = 0;
    int     rowNum  = 1;

    while(pInput[i] != '\0')
    {
//        printf("[1] i=%d, %d, %d \n", i, pInput[i], pInput[i] - '0');
        if ((pInput[i] >= '2') && (pInput[i] <= '9'))
        {
            rowNum *= Hash[pInput[i] - '0'].iLen;
            
            colNum += 1;
            i += 1;
        }
        else
        {
            colNum = 0;
            break;
        }
    }

    *pRowNum = rowNum;
    *pColNum = colNum;
    return 0;
}

char ** letterCombinations(char * digits, int* returnSize){
    char    **ppRet      = NULL;
    int     rowNum       = 0;           // 输入字符串能表示的字符组合数量
    int     colNum       = 0;           // 输入字符串数量
    int     i            = 0;
    int     j            = 0;
    int     k            = 0;
    int     interval     = 0;

    JudgeInput(digits, &rowNum, &colNum);
    
    if (colNum <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    // rowNum 行 colNum 列的二维数组，每行代表一个字母组合，列数代表字母的个数
    ppRet = (char **)malloc(sizeof(char *) * rowNum);
    *returnSize = rowNum;
    // 随着输入字母的增多，字母的组合越来越多，单对于单列来说，该列对应一个数字的字母
    // 变化是有规律的，字符一直在循环出现
    // 连续出现的次数等于后面每级字符个数的乘积
    // 拿"23"来说，2中的a处于第一级别，下一级别有3个字母，所以连续重复出现3次 
    // 这个地方通过树状图会比较好理解，a需要重复出现3次，若再加一级数字4，则a重复出现3*3 = 9次
    /***************************
        a       b       c
        |       |       |
      d e f   d e f   d e f

    ****************************/
    interval = rowNum;

    for (i = 0; i < colNum; i++)
    {
        k = Hash[digits[i] - '0'].iLen;
        interval /= k;  // 每个数字的间隔，表示后面数字有多少种组合，等于数字连续重复出现次数
        
        for (j = 0; j < rowNum; j++)
        {
            if (i == 0)
            {
                ppRet[j] = (char *)malloc(sizeof(char) * (colNum + 1));
                ppRet[j][colNum] = '\0';
            }

            //通过 Hash 表找到对应的字符（位置下标 / 数字间隔）% 数字对应的字符个数
            //经过间隔连续重复出现后，就要换下一个字符了，所以用求余的操作
            ppRet[j][i] = Hash[digits[i] - '0'].cChar[(j / interval) % (k)];
        }
    }
    return ppRet;
}

```