### 解题思路
直接算，见代码

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int i;
    int *p;
    int len;
    int row;
    int left;
    int tmp;
    int sum;
    if (widths == NULL || S == NULL || returnSize == NULL) {
        return NULL;
    }
    len = strlen(S);
    sum = 0;
    row = 1;
    for (i = 0; i < len; i++) {
        tmp = widths[S[i] - 97];
        if (sum + tmp > 100) {
            sum = 0;
            i = i - 1;
            row++;
            continue;
        } else if (sum + tmp == 100) {
            left = 100;
            sum = 0;
            row++;
            continue;
        } else {
            sum += tmp;
            left = sum;
            continue;
        }
    }
    p = (int *)malloc(sizeof(int)*2);
    p[0] = row;
    p[1] = left;
    *returnSize = 2;
    return p;
}
```