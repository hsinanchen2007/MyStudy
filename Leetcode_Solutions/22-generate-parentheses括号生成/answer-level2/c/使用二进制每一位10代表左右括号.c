### 解题思路
左括号加右括号的个数一共是2n，用一个pow(2, 2*n)的数字表示左右括号的组合。
比如n = 2时，有如下组合：
   二进制 -> 数字
1.   00       0
2.   01       1
3.   10       2
4.   11       3


bit位为1代表'('，bit位为0代表')'，能满足要求的最小值的首个bit位应该是1，也就是左括号，这个可以减小一半的遍历值。
设置两个统计量，一个是left表示左括号个数，一个是dep代表括号深度（遇到(就+1，遇到)就-1）。
遍历过程中，当left > n就验证下一个数，dep < 0说明右括号比左括号多了，跳过验证下一个数。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    int min = pow(2, 2*n - 1);
    int max = pow(2, 2*n);
    char *tmp_str = malloc(2*n + 1);
    int left, dep;
    char **ret_str = (char **)malloc(sizeof(char *) * pow(2, 2 * n));
    *returnSize = 0;

    //printf ("min %d, max %d\n", min, max);

    int i, j;
    for (i = min; i < max; i++) {
        left = dep = 0;
        uint64_t tmp = i;
        memset(tmp_str, 0, 2*n + 1);
        for (j = 0; j < 2*n; j++) {
            if ((min & tmp) != 0) {
                left++;
                dep++;
                if (left > n) {
                    break;
                }
                tmp_str[j] = '(';
            } else {
                dep--;
                if (dep < 0) {
                    break;
                }
                tmp_str[j] = ')';
            }
            tmp = tmp << 1;
        }
        if (strlen(tmp_str) == 2 * n) {
            ret_str[*returnSize] = (char *)malloc(2 * n + 1);
            strncpy(ret_str[*returnSize], tmp_str, 2 * n + 1);
            (*returnSize)++;
        }
    }

    return ret_str;
}
```