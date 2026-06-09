### 解题思路
1.首先定义状态：sum
2.初始化状态：sum=0，res=(最小值)
3.状态转移方程 res[n]=max(sum[n-1],0)+sum[n]

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0;
        //记录子序和
        int res=Integer.MIN_VALUE;
        for(int number:nums){
            if(sum<0){
                sum=0;
            }
            sum+=number;
            res=Math.max(sum,res);
        }
        return res;
    }
}
```