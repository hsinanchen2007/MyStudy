直接创建动态二维数组，折半首尾合并（1和8, 2和7，3和6.....），然后递归到只剩1行即结果。申请内存默认不会失败，未加保护。
```
char** find(char **nums, int numsSize, int numsColSize, int *returnSize, int *returnColSize)
{
    int i;
    char **res, **newRes;
    if (numsSize == 1) {
        return nums;
    }
    if (numsSize == 2) {
        res = calloc(1, sizeof(char*));
        res[0] = calloc(numsColSize * 2 + 4, sizeof(char)); /* 合并之后多3个字符，加结束符'\0' */
        res[0][0] = '(';
        (void)strcat(res[0], nums[0]);
        (void)strcat(res[0], ",");
        (void)strcat(res[0], nums[1]);
        (void)strcat(res[0], ")");
        *returnSize = 1;
        *returnColSize = 2 * numsColSize + 3; /* 合并之后多3个字符 */
        free(nums[0]);
        free(nums[1]);
        free(nums);
        return res;
    }
    res = calloc(numsSize / 2, sizeof(char*));
    for (i = 0; i < numsSize / 2; i++) {
        res[i] = calloc(numsColSize * 2 + 4, sizeof(char));
        res[i][0] = '(';
        (void)strcat(res[i], nums[i]);
        (void)strcat(res[i], ",");
        (void)strcat(res[i], nums[numsSize - 1 - i]);
        (void)strcat(res[i], ")");
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != NULL) {
            free(nums[i]);
        }
    }
    free(nums);
    newRes = find(res, numsSize / 2, 2 * numsColSize + 3, returnSize, returnColSize);
    return newRes;
}
char * findContestMatch(int n)
{
    char **res, **nums;
    char *ans;
    int i;
    int returnSize, returnColSize;
    nums = calloc(n, sizeof(char*));
    for (i = 1; i <= n; i++) {
        nums[i - 1] = calloc(5, sizeof(char)); /* 4096最多5位足够 */
        (void)sprintf(nums[i - 1], "%d", i);
    }
    res = find(nums, n, 4, &returnSize, &returnColSize); /* 参数3最多4位有效 */
    ans = calloc(returnColSize + 1, sizeof(char));
    strcpy(ans, res[0]);
    free(res[0]);
    free(res);
    return ans;
}
```
