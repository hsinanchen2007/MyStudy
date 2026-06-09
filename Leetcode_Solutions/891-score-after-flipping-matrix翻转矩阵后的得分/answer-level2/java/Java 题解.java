只选择性对行进行反转即可。

public int matrixScore(int[][] A) {
    if (A.length == 0 || A[0].length == 0) {
        return 0;
    }
    // 行转
    for (int i = 0; i < A.length; i ++) {
        if (A[i][0] == 0) {
            // 转动该行
            for (int j = 0; j < A[i].length; j ++) {
                A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }
    }
    // 这里不转列。直接求结果
    int sum = 0;
    for (int i = 0; i < A[0].length; i ++) {
        int count1 = 0;
        // 求出 此列中 1 的个数
        for (int j = 0; j < A.length; j ++) {
            if (A[j][i] == 1) {
                count1 ++;
            }
        }
        // 如果 1 的个数 (count1)小于行数的半数
        if (count1 < A.length / 2 + A.length % 2) {
            // 1 的个数，改为  count1 = A.length - count1; 行数 - count1
            count1 = A.length - count1;
        }
        // sum 左移 1位 + count1
        sum =(sum << 1) + count1;
    }
    return sum;
}