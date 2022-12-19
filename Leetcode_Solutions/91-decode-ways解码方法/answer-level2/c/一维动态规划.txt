### 解题思路
动归
字符串长为1和长为2直接判断。并计算出dp[1]和dp[2],dp[3-10000] = {0}
长度超过2，从第3个字符开始判断:
  如果第三个字符能单独编码，则单独编码，那此时长为3的字符串编码个数与长为2的字符串编码个数相同dp[3] += dp[2]
  如果第三个字符与第二个字符一起能编码为一个数字，则后两位一起编码，那此时长为3的字符串编码个数与长为1的字符串编码个数相同dp[3] += dp[1]



### 代码

```c

int TwoNum(char a, char b)
{
    if (a == '0') {
        return 0;
    }
    else if (a == '1') {
        return b == '0' ? 1 : 2;
    }
    else if (a == '2') {
        if (b == '0') {
            return 1;
        }
        else {
            return b > '6' ? 1 : 2;
        }
    }
    else {
        return b == '0' ? 0 : 1;
    }
}

int IsAlaph(char a, char b)
{
    if (a == '1') {
        return 1;
    } else if (a == '2') {
        return b > '6' ? 0 : 1;
    } else {
        return 0;
    }
}

int numDecodings(char * s)
{
    int len = strlen(s);
    if (len == 1) {
        return s[0] == '0' ? 0 : 1;
    }
    if (len == 2) {
        return TwoNum(s[0], s[1]);
    }
    int i = 0;
    int dp[100000] ={0};
    dp[0] = s[0] == '0' ? 0 : 1;
    dp[1] = TwoNum(s[0], s[1]);
    for (i = 2; i < len; i++) {
        if (s[i] != '0') {
            dp[i] += dp[i-1];
        }
        if (IsAlaph(s[i-1], s[i]) == 1) {
            dp[i] += dp[i-2];
        }
    }
    return dp[i-1];
}
```