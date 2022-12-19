动态规划，使用二维数组辅助，规律很简单，直接看图。
先计算第一行第一列，然后从第二行第二列开始逐行计算。
最后一行之和即为答案。
![image.png](https://pic.leetcode-cn.com/cea5d406502ef1af1a5367f74b75424640db013db96d6b12b9d375774822631b-image.png)
![image.png](https://pic.leetcode-cn.com/a3295ee8e71e2fc6328ceaa97cef5fc6590a123f756e57a75ade88082062ce6c-image.png)

```c
int numDistinct(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    if ((slen == 0) || (tlen == 0)) return 0;
    long dp[tlen][slen]; // 注意，要用long，否则有溢出风险。
    for (int i = 0; i < slen; i++) {
        dp[0][i] = (s[i] == t[0]) ? 1 : 0;
    }
    for (int i = 1; i < tlen; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < tlen; i++) {
        long temp = 0;
        for (int j = 1; j < slen; j++) {
            temp += dp[i - 1][j - 1];
            dp[i][j] = (t[i] == s[j]) ? temp : 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < slen; i++) {
        sum += dp[tlen - 1][i];
    }
    return sum;
}
```
![image.png](https://pic.leetcode-cn.com/7a0d4ffc22c97f3203428886b25b385440fe2d1f6b33b8bcc8b4ccefa3999d07-image.png)
