### 解题思路
![image.png](https://pic.leetcode-cn.com/0b5240d853ed7853d955ee5bcb02f356a82d0fdac54dc1b0cda8efe69df8de56-image.png)
 1. int 转换为char数组 
 2. 动态规划 dp[i] = dp[i-1] + if((i-1)*10 + i) <= 25 ? dp[i-2] : 0

### 代码

```c
// 1. int 转换为char数组 
// 2. 动态规划 dp[i] = dp[i-1] + if((i-1)*10 + i) <= 25 ? dp[i-2] : 0

#define CHAR_ARRAY_SIZE 11
int translateNum(int num)
{
    if (num < 0) {
        return 0;
    }

    // 1. num转换为char数组
    char str[CHAR_ARRAY_SIZE] = {-1};
    sprintf(str, "%d", num); 
    int strLen = strlen(str);
 
    // 2. 动态规划
    int dp[CHAR_ARRAY_SIZE] = {0};
    dp[0] = 1; // 1个数字

    int value = (str[0] - '0') * 10 + (str[1] - '0'); // 计算dp[1] 即2个数字时
    if (value >= 10 && value <= 25) {
        dp[1] = 2;
    } else {
        dp[1] = 1;
    }

    for (int i = 2; i < strLen; i++) {
        int temp = (str[i - 1] - '0') * 10 + (str[i] - '0'); // 转为int
        if (temp >= 10 && temp <= 25) {
            dp[i] = dp[i - 1] + dp[i - 2];
        } else {
            dp[i] = dp[i - 1];
        }
    }

    return dp[strLen - 1];
}
```