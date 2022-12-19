解法：
使用数组记录机器人走过的位置，
每走一步判断坐标是否合法，再判断上方或左方是否走过；
```c
int sumOfNumBit(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int movingCount(int m, int n, int k) {
  int i, j, cnt = 0, **dp = (int **)malloc(sizeof(int *) * m);
  for (i = 0; i < m; i++) {
    dp[i] = (int *)calloc(n, sizeof(int));
    for (j = 0; j < n; j++) {
      if (sumOfNumBit(i) + sumOfNumBit(j) <= k) {                                                            //坐标合法
        if ((i == 0 && j == 0) || (i - 1 >= 0 && dp[i - 1][j] == 1) || (j - 1 >= 0 && dp[i][j - 1] == 1)) {  //原点，上方，左方
          cnt++;
          dp[i][j] = 1;
        }
      }
    }
  }
  return cnt;
}
```