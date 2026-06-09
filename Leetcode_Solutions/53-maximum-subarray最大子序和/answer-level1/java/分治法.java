### 解题思路
> 找 子序列的最大和值
>
> 这一题是 分治法的 经典题目
>
> 分为两半
>
> 整体的最大和 一定是 左侧 右侧 中间[涉及左右两侧] 中的 最大和值
>
> 
>
> 分解问题：分治法 需要 用到 递归...去分解问题 
>
> ​					helper(left,right,nums){
>
> ​							递归出口
>
> 
>
> ​							<font color="red">计算左</font>

> ​							<font color="red">计算右</font>							
>
> ​							计算中间子序列
>
> ​							
>
> ​							返回 最大的和值
>
> ​					}
>
> 处理问题：也在helper中
>
> ​			1）递归出口(**得出结果的关键**)
>
> ​			2）计算中间子序列
>
> ​			3) return Max(左 中 右)
>
> 
>
> 合并问题: 只要找到最大和值 合并问题 
>
> 可以看做 return Max() 返回到上一层 **得出 左 右 再结合 中间 又得出max

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        return helper(0,nums.length-1,nums);
    }

     //分治法. 递归...
    //返回值:当前子串的最大子序列的和值
    public int helper(int left,int right,int nums[]){
        //递归出口...  left == right
        if(left==right) return nums[left];

        //找到中间点... 奇数个数字 mid 归于左
        int mid = (right+left)>>>1;

        //分治
        //计算 左 右 中
        int leftSubSum = helper(left,mid,nums); // 递归到 递归出口 即可得出 返回出结果...
        int rightSubSum = helper(mid+1,right,nums);
        //计算涉及左右两边的子序列之和... 另写方法
        int crossSubSum = crossSum(left,mid,right,nums);

        return Math.max(Math.max(leftSubSum,rightSubSum),crossSubSum);
    }

     //计算分治后 中间[涉及两边]的子序列
    //从mid往两边延伸... 分别找到两侧的最大子序列之和...
    public int crossSum(int left,int mid,int right,int nums[]){
        //从mid往左遍历
        int leftSumMax = Integer.MIN_VALUE;
        int currSum = 0;//计算和...
        for(int i=mid;i>left-1;i--){
            currSum += nums[i];
            leftSumMax = Math.max(leftSumMax,currSum);
        }

        //从mid往右遍历
        int rightSumMax = Integer.MIN_VALUE;
        currSum = 0;
        for(int i=mid+1;i<right+1;i++){
            currSum += nums[i];
            rightSumMax = Math.max(rightSumMax,currSum);
        }

        //leftSumMax就是 从Mid往左 的 最大和值  rightSumMax 同样
        return leftSumMax+rightSumMax;
    }

}
```