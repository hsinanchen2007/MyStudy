### 解题思路
这题使用递归解也比较简单，就是发现n=100时超时，以为运算太慢（应该是原因这一），实际是组合太多；
实际第n个数的组合是前两个数组合的和；
1--1
2--2
3--3
4--5
5--8
6--13
这样，我们只要两个数n=1与n=2就可以了，每次都替换其中一个，以此类推。
![123.PNG](https://pic.leetcode-cn.com/7cd8dd9e75e7dbf511253cd776583b338d255293cc3b9a42658fe4b3b2578c51-123.PNG)


### 代码

```c
int climbStairs(int n) {
    unsigned int dp[2] = { 1, 2 };
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    unsigned int result = 0;;
    for (int i = 3; i <= n; i++) {
        unsigned int tmp = dp[0] + dp[1];
        result = tmp;
        dp[(i + 1) % 2] = tmp;
    }
    return result;
}
```