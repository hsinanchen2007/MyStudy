int uniquePaths(int m, int n)
{
    if((m==1)&&(n==1)){
        return 1;
    }
    long num[m][n];
    m = m - 1;
    n = n - 1;
    int i = 0;
    int j = 0;
    memset(&num, 0, sizeof(num));
    //第n列，到终点的目标只有1种路径
    for (i = 0; i < m; i++) {
        num[i][n] = 1;
    }
    //第m行，到终点的目标路径只有1种
    for (i = 0; i < n; i++) {
        num[m][i] = 1;
    }
    //当前位置到终点的路径数是他右边位置路径数+下边路径数
    for (i = m - 1; i >= 0; i--) {
        for (j = n - 1; j >= 0; j--) {
            num[i][j] = num[i + 1][j] + num[i][j + 1];
        }
    }
    return num[0][0];
}