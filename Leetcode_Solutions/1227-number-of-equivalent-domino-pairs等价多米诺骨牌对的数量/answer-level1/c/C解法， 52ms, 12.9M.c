**思路**
将每一种对子的总个数统计到一个9 x 9的矩阵中，最后通过等差数列求和计算出每种组合的总个数。

int pairs[9][9] = {0};

int calcTotal(int n)
{
    return (n * (n - 1)) >> 1;  // 等差数列求和
}
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int cnt = 0;
    memset(pairs, 0, sizeof(pairs));
    if (dominoesSize > 40000) {
        return 0;
    }
    for (int i = 0; i < dominoesSize; i++) {
        pairs[dominoes[i][0] - 1][dominoes[i][1] - 1]++;        // 统计9 x 9 的矩阵中每个位置上对子的总个数。
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j < i; j++) {
            int num = pairs[i][j] + pairs[j][i];
            if (num) {
                cnt += calcTotal(num);             // 非对角线上的组合总数
            }
        }
    }
    for (int i = 0; i <= 8; i++) {
        int num = pairs[i][i];
        if (num) {
            cnt += calcTotal(num);  // 对角线上的组合总数
        }
    }
    return cnt;
}

