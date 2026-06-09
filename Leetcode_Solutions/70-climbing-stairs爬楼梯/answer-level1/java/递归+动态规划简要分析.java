递归解法：
```java []
class Solution {
    public int climbStairs(int n) {
        if (n < 0) { // 排除不是正整数的情况
            return -1;
        }
        if (n <= 2) { // 列出基本情况
            return n;
        }
        // 根据公式 f(n) = f(n - 1) + f(n - 2)
        // 思路很简单，但这个方法会超时
        // 原因：
        // f(3) = f(2) + f(1)
        // f(4) = f(3) + f(2)
        //      = f(2) + f(1) + f(2)
        // 由此可见这个方法会引入非常多的重复运算
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}
```
```go []
func climbStairs(n int) int {
	if n <= 2 {
		return n
	}
	return climbStairs0(n-1) + climbStairs0(n-2)
}
```

动态规划解法：
```java []
class Solution {
    public int climbStairs(int n) {
        if (n < 0) { // 排除不是正整数的情况
            return -1;
        }
        if (n <= 2) { // 最基本情况
            return n;
        }
        // 其实这道题不需要递归，只需要两个变量
        // 保存 f(n - 1) 跟f(n - 2)的值就行了
        int pre2 = 1, pre1 = 2;
        for (int i = 2; i < n; ++i) {
            int temp = pre1;
            pre1 = pre1 + pre2;
            pre2 = temp;
        }
        return pre1;
    }
}
```
```go []
func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    pre2, pre1 := 1, 2
    for i := 2; i < n; i++ {
        pre2, pre1 = pre1, pre2 + pre1
    }
    return pre1
}
```
