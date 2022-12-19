### 解题思路
每条边至少会参与一次计算，固定第一个顶点和最后一个顶点组成的边，在剩余顶点中取任一顶点，均可将
凸多边形分成两个小凸边形和一个三角形，迭代公式如下：
dp(i, j) = dp(i, k) + dp(k, j) + A[i] * A[k] * A[j]; i < k < j
当j - i等于2时:dp(i, j) = A[i] * A[i + 1] * A[j];

### 代码

```c

unsigned int res_cache[51][51] = {0};

unsigned int dp(int *A, int ASize, int start, int end)
{
    int i;
    int n = end - start;
    unsigned int res;
    unsigned int tmp;

    if (n < 2)
        return 0;

    if (res_cache[start][end] > 0)
        return res_cache[start][end];

    if (n == 2) {
        res = A[start] * A[start + 1] * A[end];
        res_cache[start][end] = res;
        return res;
    }

    res = 0xffffffff;
    for (i = start + 1; i < end; i++) {
        tmp = A[start] * A[i] * A[end];        
        if (i == end - 1) {
            tmp += dp(A, ASize, start, i);
        } else {
            tmp += dp(A, ASize, start, i) + dp(A, ASize, i, end);
        }
        if (res > tmp)
            res = tmp;
    }

    res_cache[start][end] = res;
    return res;
}

int minScoreTriangulation(int* A, int ASize){
    memset(res_cache, 0, sizeof(res_cache));
    return dp(A, ASize, 0, ASize - 1);
}
```