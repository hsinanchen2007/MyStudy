### 解题思路
枚举所有的shorter和longer的组合，如果length和上次添加进数组的length不相等，则添加，否则不添加

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* divingBoard(int shorter, int longer, int k, int* returnSize){
    int *ret = (int *)malloc(sizeof(int) * 100000);
    memset(ret, 0, sizeof(int) * 100000);
    *returnSize = 0;
    int prev = 0;
    for(int i = 0; i <= k; i++) {
        int length = shorter * (k - i) + longer * i;
        
        if (length != prev) {
            ret[(*returnSize)++] = length;
        }
        prev = length;
    }
    return ret;
}
```