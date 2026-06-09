### 解题思路
```java
示例数组：
数组值 [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
索引位置0   1    2  3  4  5   6   7   8   9
```

#### 递归

```java
数组值 [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
索引位置0   1    2  3  4  5   6   7   8   9
```
**递归最大的问题就是重复计算的问题**

#### 遍历

```java
    数组值 [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    索引位置0   1    2  3  4  5   6   7   8   9
```
设： P(10) = 0; P(11) = 0
```java
	索引9的最优值： 1 + min(P(10),P(11))   = 1
	索引8的最优值： 100 + min(P(9),P(10)) = 101
	索引7的最优值：  1 + min(P(9),P(8)) =  2
	索引6的最优值：  1 + min(P(7),P(8)) = 3
	索引5的最优值：   100 + min(P(6),P(7)) = 102
	索引4的最优值：  1 + min(P(5),P(6)) = 4
	索引3的最优值：   1+min(P(4),P(5)) = 5
	索引2的最优值：   1+min(P(3),P(4)) = 5
	索引1的最优值：   100 + min(P(2),P(3)) = 105
	索引0的最优值：   1+min(P(1),P(2)) = 6

min(P(0),P(1)) = 6
```

### 代码

```java
class Solution {
    /*
     * 避免重复计算，应该从后往前计算
     */
    public int minCostClimbingStairs(int[] cost) {
        int before = 0; //如10
        int beforeLast = 0;//如11
        int i = cost.length-1;
        while(i >= 0) {
            int m = cost[i] + before;
            int n = cost[i] + beforeLast;
            beforeLast = before;
            before = Math.min(m,n);
            i--;
        }
        return Math.min(before,beforeLast);
    }

    /*
     * 重复计算了，递归
    public int minCostClimbingStairs(int[] cost) {
        int fromZero = get(cost,0);
        int fromOne = get(cost,1);
        return Math.min(fromZero,fromOne);
    }

    private int get(int[] cost,int fromIdx) {
        if(fromIdx >= cost.length) {
            return 0;
        }
        int sum = cost[fromIdx];
        int a = get(cost,fromIdx+1);
        int b = get(cost,fromIdx+2);
        return sum + Math.min(a,b);
    }
    */
}
```