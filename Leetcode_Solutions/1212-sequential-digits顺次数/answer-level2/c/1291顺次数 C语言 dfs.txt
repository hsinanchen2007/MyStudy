### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

// dfs ：往当前位置pos填一个数，更新curnum
void dfs(int low, int high, int *ans, int *len, int pos, int curnum)
{
    if (curnum >= low && curnum <= high) {
        ans[*len] = curnum;
        (*len)++;
    }
    if (curnum > high) {
        return;
    }
    
// 如果当前位置为0；那么这个位置填几都可以
    if (pos == 0) {
        for (int i = 1; i < 10; i++) {
            dfs(low, high, ans, len, 1, curnum + i);
        }
// 如果当前位置 > 0，那么先得到curnum 的末位数，pos 位置填的数要比这个数大1
    } else {
        int a = curnum;
        while(pos > 1) {
            a = curnum % ((--pos) * 10);
        }
        if (a == 9) {
            return;
        } else {
            dfs(low, high, ans, len, pos + 1, curnum * 10 + a + 1);
        }
        
    }
}
int* sequentialDigits(int low, int high, int* returnSize){
    int *ans = (int*)malloc(sizeof(int) * 2048);
    int len = 0;
    dfs(low, high, ans, &len, 0, 0);

    *returnSize = len;
    qsort(ans, len, sizeof(int), cmp);
    return ans;
}

```