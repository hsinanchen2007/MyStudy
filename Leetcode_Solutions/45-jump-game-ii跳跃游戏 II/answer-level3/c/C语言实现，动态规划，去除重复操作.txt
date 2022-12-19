![image.png](https://pic.leetcode-cn.com/d106f6ce67dc949419b37e100cc228d1813b5e96b20549402e92113c74592719-image.png)


```
int jump(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) return 0;
    int *dest = malloc(numsSize * sizeof(int));
    memset(dest, -1, numsSize * sizeof(int));
    dest[0] = 0;
    int ret;
    for (int i = 0; i < numsSize; ++i) {
        if (dest[i] == -1) continue;
        for (int j = i + nums[i] < numsSize - 1 ? i + nums[i] : numsSize - 1; j > i; --j) {
            if (dest[j] == -1) {
                dest[j] = dest[i] + 1;
            } else if (dest[j] <= dest[i] + 1) { // 已经是最优解,前面的都是最优解
                break;
            } else { // 不是最优解,需要更新
                dest[j] = dest[i] + 1;
            }
            if (j == numsSize - 1) goto FINSH;
        }
    }
FINSH:
    ret = dest[numsSize - 1];
    free(dest);
    return ret;
}
```
