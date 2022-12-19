### 解题思路
执行用时 :
124 ms, 在所有 C 提交中击败了90.12%的用户
内存消耗 :
18.2 MB, 在所有 C 提交中击败了100.00%的用户
这题，貌似应该属于简单类啊。。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;

    int *buf = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(buf, 0, sizeof(int) * (numsSize + 1));
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        buf[nums[i]]++;
        if (buf[nums[i]] == 2) {
            cnt++;
        }
    }
    int *out = (int *)malloc(sizeof(int) * cnt);
    memset(out, 0, sizeof(int) * cnt);
    int j = 0;
    for (int i = 0; i < (numsSize + 1); i++) {
        if (buf[i] == 2) {
            out[j++] = i;
        }
    }
    free(buf);
    buf = NULL;
    *returnSize = cnt;
    return out;
}
```