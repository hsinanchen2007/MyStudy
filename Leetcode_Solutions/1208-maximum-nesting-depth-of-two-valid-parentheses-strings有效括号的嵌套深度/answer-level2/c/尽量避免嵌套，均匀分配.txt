### 解题思路
尽量避免嵌套。
所以维护一个0的左括号数量、1的左括号数量，两者尽量轮流来。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    if (!seq) {
        *returnSize = 0;
        return NULL;
    }

    int len = strlen(seq);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    int pairs = 0;
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') pairs += 1;
    }

    int cnt1 = pairs / 2;
    int cnt0 = pairs - cnt1;
    int left1 = 0;
    int left0 = 0;
    int right1 = 0;
    int right0 = 0;

    int *ans = (int*)malloc(sizeof(int) * len);
    (void)memset(ans, 0, sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            if (left1 > left0 && cnt0) {
                left0++;
                ans[i] = 0;
            } else {
                left1++;
                ans[i] = 1;
            }
        } else {
            if (left1) {
                left1--;
                cnt1--;
                ans[i] = 1;
            } else {
                left0--;
                cnt0--;
                ans[i] = 0;
            }
        }
    }

    *returnSize = len;
    return ans;
}
```