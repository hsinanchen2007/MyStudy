### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize)
{
    int minDigitNum = getDigitNum(low);
    int maxDigitNum = getDigitNum(high);
    int baseNum;
    int diffNum;
    int resSize = 0;
    int *res = NULL;

    if (low > high) {
        *returnSize = 0;
        return NULL;
    }

    res = (int *)malloc(sizeof(int) * 36);

    for (int i = minDigitNum; i <= maxDigitNum; i++) {
        baseNum = creatBase(i);
        diffNum = createDiff(i);
        while ((baseNum <= high) && ((baseNum % 10) != 0)) {
            if (baseNum >= low) {
                res[resSize++] = baseNum;
            }

            baseNum += diffNum;
        }
    }

    *returnSize = resSize;
    return res;
}

int getDigitNum(int n)
{
    int i = 0;
    while (n > 0) {
        n = n / 10;
        i++;
    }

    return i;
}

int creatBase(int digitNum)
{
    int res = 0;
    for (int i = 1; i <= digitNum; i++) {
        res = res * 10 + i;
    }

    return res;
}

int createDiff(int digitNum)
{
    int res = 0;
    for (int i = 1; i <= digitNum; i++) {
        res = res * 10 + 1;
    }

    return res;
}
```