### 解题思路
//回溯法:
//1，画出树形图，找到结束条件 left==right==0
//2，确定移动下标，数组下标 index 作为移动下标，每一层则 index+1
//3，找到分支条件，左分支控制标志 left>0  右分支控制 right>left
//4，左分支回溯，移动下标index+1，左分支控制left-1
//5，右分支回溯，移动下标index+1，右分支控制right-1

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 计算n的C(2n)(n) 表示n对括号共有多少种排列组合
int calculateNums(int n)
{
    int         i       = 0;
    int         iNum    = 0;
    long int    lNum_1  = 1;
    long int    lNum_2  = 1;

    for (i = 0; i < n; i++)
    {
        lNum_1 *= 2 * n - i;
        lNum_2 *= n - i;
    }
    iNum = (int)(lNum_1 / lNum_2);

    return iNum;
}

void generate(char *item, int index, int left, int right, char **result, int *count, int n)
{
    if (left == 0 && right == 0)
    {
        result[(*count)] = (char *)malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[(*count)++], item);
        return;
    }

    item[index] = '(';
    item[index + 1] = '\0';

//    printf("index=%d, left=%d, right=%d, count=%d\n", index, left, right, *count);

    if (left > 0)
    {
//        printf("[1]:index=%d, left=%d, right=%d, count=%d\n", index, left, right, *count);
        generate(item, index + 1, left - 1, right, result, count, n);
    }

    if (right > left)
//    if (right > 0)
    {
//        printf("[2]:index=%d, left=%d, right=%d, count=%d\n", index, left, right, *count);

        item[index] = ')';
        generate(item, index + 1, left, right - 1, result, count, n);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char    **ppRet     = NULL;
    char    *item       = NULL;
    int     iNum        = 1;
    int     iLeft       = n;
    int     iRight      = n;

    int     iCount      = 0;
    int     index       = 0;

    iNum = calculateNums(n);

    printf("iNum=%d\n", iNum);

    ppRet = (char **)malloc(sizeof(char *) * iNum);
    item = (char *)malloc(sizeof(char) * (2 * n + 1));

    generate(item, index, iLeft, iRight, ppRet, &iCount, n);
    *returnSize = iCount;

    return ppRet;
}
















```