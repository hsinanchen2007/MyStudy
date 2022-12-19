### 解题思路
执行用时 :
20 ms, 在所有 C 提交中击败了92.85%的用户
内存消耗 :
8.2 MB, 在所有 C 提交中击败了100.00%的用户
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int cnt;
    int buf;
} Top;

Top g_top[2000] = {0};
int Com(const void *a, const void *b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    return a1 < b1;
}

int Com1(const void *a, const void *b)
{
    Top a1 = *(Top *)a;
    Top b1 = *(Top *)b;
    if (a1.cnt != b1.cnt) {
        return a1.cnt < b1.cnt;
    }
    return a1.buf > b1.buf;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    * returnSize = 0;
    memset(g_top, 0, sizeof(g_top));
    qsort(nums, numsSize, sizeof(int), Com);

    int len = 0;
    bool same = true;
    for (int i = 0; i < numsSize - 1; i++) {
            g_top[len].cnt++;
            g_top[len].buf = nums[i];
        if (nums[i] == nums[i + 1]) {
            same = true;
            continue;
        }
        len++;
        same = false;
    }
    if (same) {
        g_top[len].cnt++;
    } else {
        len++;
        g_top[len].cnt = 1;        
    }
    g_top[len].buf = nums[numsSize - 1];
    len++;
    qsort(g_top, len, sizeof(Top), Com1);

    int *out = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        out[i] = g_top[i].buf;
    }
    *returnSize = k;
    return out;
}
```