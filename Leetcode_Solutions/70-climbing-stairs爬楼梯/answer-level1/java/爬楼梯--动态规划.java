### 解题思路
此题运用动态规划，对所得到的每一步结果都进行记录；
因为至少要记录前两个元素，才能进行迭代。
所以对n<2的情况要单独处理

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n < 2){
            return n;
        }
        int [] res = new int[n + 1];
        res[1] = 1;
        res[2] = 2;
        for(int i = 3; i <= n; i++){
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
}
```