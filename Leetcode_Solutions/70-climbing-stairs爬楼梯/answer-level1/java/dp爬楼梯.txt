### 解题思路
先确定这是线性的题目

第一步找到子问题：到第i层楼梯需要多少种方法；

第二步找到每个子问题的状态方程：第i层
（1）爬一个楼梯到第i层要多少种方法 typeOne[i]；
（2）爬两个楼梯的第二下到第i层需要多少种方法 typeTwo[i]；

第三步找状态转移方程：从第i-1层到第i层：
（1）从第i-1层爬一个楼梯到第i层 typeOne[i] = typeOne[i-1] + typeTwo[i-1];
（2）从第i-1层爬两个楼梯第二下到第i层需要多少种方法 typeTwo = typeOne[i-1];

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        int typeOne = 1;
        int typeTwo = 0;
        for (int i=1;i<n;i++) {
            int temp = typeOne;
            typeOne = typeOne + typeTwo;
            typeTwo = temp;
        }
        return typeTwo + typeOne;
    }
}
```