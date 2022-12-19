### 解题思路
此题可用递归的方式可以做，使用循环做法的结果为：
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户;
内存消耗 :32.8 MB, 在所有 Java 提交中击败了73.98%的用户

一次可以走一步或者两步。你要到第五层 = 你到第四层的步数在走一步 + 你到第三层的步数在走两步
即：f(n) = f(n - 1) + f(n - 2);
初始化：
第一层 = 一步到达 = 1
第二层 = 两次一步到达 + 一次两步到达 = 2
第三层 = 第二层走一步 + 第一层走两步
......

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        int[] steps = new int[n+2];

        steps[1] = 1;
        steps[2] = 2;

        for(int i = 3; i <= n; i++){
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n];
    }
}
```