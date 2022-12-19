### 解题思路
斐波那契数列 + 循环解决 + 思路应该是dp思路

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        //斐波那契数列
        //定义辅助数组
        int[] list = new int[n];
        
        //第一步值
        list[0] = 1;


        if (n >= 2) {
            list[1] = 2;
        }
        
        //循环计算每一步所走的台阶
        for (int i = 2; i < n; i++) {
            list[i] = list[i-1] + list[i-2];
        }
        
        return list[n-1];
    }
}
```