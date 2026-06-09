A[k] * 2 != A[i] + A[j]，则A[k] * 2 * 2 != A[i] * 2 + A[j] * 2成立
若A[i]为奇数，A[j]为偶数，则能使上述公式成立
        odd               even
DP(3)：[1 3               2]
DP(4)：[1 3               2 4]
DP(5)：[1 5 3             2 4]
DP(6) = [[DP(3) * 2 - 1]  [DP(3) * 2]] = [1 5 3  2 6 4]
DP(7) = [[DP(4) * 2 - 1]  [DP(3) * 2]] = [1 5 3 7 2 6 4]
...
根据以上规律，得到如下迭代公式:
DP(N) = [[DP((N + 1)/2) * 2 - 1] [DP(N / 2) * 2]]


代码:
int buf[500];

void dp(int *res, int N)
{
    int i;
    int j;
    int n;

    if (N == 3) {
        res[0] = 1;
        res[1] = 3;
        res[2] = 2;
        return;
    } else if (N == 4) {
        res[0] = 1;
        res[1] = 3;
        res[2] = 2;
        res[3] = 4;
        return;
    } else if (N == 5) {
        res[0] = 1;
        res[1] = 5;
        res[2] = 3;
        res[3] = 2;
        res[4] = 4;
        return;
    }

    // [DP(N / 2) * 2]]
    n = (N >> 1);
    dp(res, n);
    j = ((N + 1) >> 1);
    for (i = 0; i < n; i++) {
        res[j++] = (res[i] << 1);
    }

    // [DP((N + 1)/2) * 2 - 1]
    if ((N % 2) == 1) {
        n = ((N + 1) >> 1);
        dp(res, n);
    }
    j = 0;
    for (i = 0; i < n; i++) {
        res[j++] = (res[i] << 1) - 1;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int N, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * N);

    if (N < 3) {
        int i;
        for (i = 0; i < N; i++)
            res[i] = i + 1;
        
        *returnSize = N;
        return res;
    }

    dp(res, N);
    *returnSize = N;
    return res;
}