### 解题思路
前面的代码有些冗余，整体的思路是，找出规律，直接套用，比较简单。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int *res = (int*)malloc((num+1)*sizeof(int));
    *returnSize = 0;
    if(num == 0) {
        res[0] = 0;
        *returnSize = 1;
        return res;
    }
    if(num == 1) {
        res[0] = 0;
        res[1] = 1;
        *returnSize = 2;
        return res;
    }
    if(num == 2) {
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        *returnSize = 3;
        return res;
    }
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    int i = 0;
    for(i = 3; i <= num; i++) {
        if (i % 2 == 0) {
            res[i] = res[i/2];
        } else {
            res[i] = res[i/2] + 1;
        }
    }
    *returnSize = i;
    return res;
}
```