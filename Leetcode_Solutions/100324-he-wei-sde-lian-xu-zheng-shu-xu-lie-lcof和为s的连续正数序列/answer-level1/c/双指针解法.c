![image.png](https://pic.leetcode-cn.com/b02a7fba2f51eaa394cb6311778629077214db1553c1a860cc2d5b4da496c1fb-image.png)

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int len = (target + 1) / 2;
    int** res = (int**)malloc(sizeof(int*) * target);
    *returnColumnSizes = (int*)malloc(sizeof(int) * target);
    int cnt = 0;

    int start = 1, end = 2;
    *returnSize = 0;

    while (start < end && end <= len) {
        cnt = (end - start + 1) * (start + end) / 2;

        if (cnt == target) {
            res[*returnSize] = (int*)malloc(sizeof(int) * (end - start + 1));
            for (int i = start; i <= end; i++) {
                res[*returnSize][i - start] = i;
            }

            (*returnColumnSizes)[*returnSize] = end - start + 1;
            (*returnSize)++;
            start++;
        } else if (cnt < target){
            end++;
        } else if (cnt > target) {
            start++;
        }

        cnt = 0;
    }

    return res;
}
```



