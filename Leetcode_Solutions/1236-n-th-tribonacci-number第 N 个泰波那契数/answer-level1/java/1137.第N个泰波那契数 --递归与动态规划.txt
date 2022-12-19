### 解题思路
利用递归求解时，会出现超出时间限制的问题，因此采用循环的方法实现，时间复杂度为O(n),空间复杂度为O(1)

1. 递归实现，可以通过36个测试用例，当n = 35是开始出现超出时间限制问题
### 代码

```java
class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n ==1 || n == 2) return 1;
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
    }
}
```

2. 动态规划实现，执行时间0ms
### 代码

```java
class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n ==1 || n == 2) return 1;
        int one = 0, two = 1, three = 1;
        int res = 0;
        for (int i = 3; i < n + 1; i++) {
            res = three + two + one;
            one = two;
            two = three;
            three = res;
        }
        return res;
        
    }
}
```