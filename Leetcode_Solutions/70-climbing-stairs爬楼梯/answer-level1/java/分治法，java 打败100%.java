### 解题思路
第一种是折半，那么有 climbStairs(n/2)*climbStairs(n-n/2)种方式
第一种是将刚刚的两半的末尾和开始的1合为2，那么有climbStairs(n/2-1)*climbStairs(n-n/2-1)种方式
所以climbStairs(n/2)*climbStairs(n-n/2)+climbStairs(n/2-1)*climbStairs(n-n/2-1)
T(n)=4T(n/2)+O(1) //O(1)就是合并子问题答案需要的复杂度

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        return climbStairs(n/2)*climbStairs(n-n/2)+climbStairs(n/2-1)*climbStairs(n-n/2-1);
    }
}
```