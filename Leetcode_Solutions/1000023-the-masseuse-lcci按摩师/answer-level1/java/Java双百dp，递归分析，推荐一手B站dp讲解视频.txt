### 解题思路
直接上链接https://b23.tv/BV12W411v7rd 里面分析问题的方法很受用，我在这里简单描述下，
题目大概意思选出和最大的数字组合，且数字不能相邻。

输入数组数据
index 0 1 2 3
val   1 2 2 4
我们假定一个函数opt(int i),他返回的是参数索引范围内的最优解，对于数组里的任意一个元素有两种情况，选或者不选，
opt(i=3,nums)
选择的情况下：加上他本身4去寻找与他不相邻的数组找最大值，nums[i]+opt(i-2)
不选 opt(i-1,nums)
判断条件是什么呢？取两种情况数值大者
临界条件 i=0
public int opt(int i ,int[] nums){
if(i==0)return nums[0];
if(i==1)return Math.max(nums[0],nums[1]);
return Math.max(opt(i-1,nums),nums[i]+opt(i-2,nums));
}
把递归的情况从头开始推就可以dp,正推从第一个满足递归式的i=2开始
 


### 代码

```java
class Solution {
//     1 3 1 1
    public int massage(int[] nums) {
        if (nums.length==0){
            return 0;
        }else if (nums.length==1){
            return nums[0];
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] =  Math.max(nums[0],nums[1]);
        for (int i=2;i<nums.length;i++){
            dp[i] =Math.max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.length-1];
    }
}
```