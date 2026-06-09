### 解题思路
首先，设状态为下标值
状态转义方程为f(i)=f(i-c)+nums(c),其中c为数组下标，
将nums复制到一个比nums数组大2的数组mid中，index从nums.length-1开始，由此将数组最后一项与其它项的处理方法进行统一处理


### 代码

```java
class Solution {
    int[] memo = null;
    public int massage(int[] nums) {   
        if(nums==null||nums.length<0){
            return 0;
        } 
        memo = new int[nums.length+2];
        Arrays.fill(memo,-1);
        int[] mid = new int[nums.length+2];//将原数组中所有的数据项的处理统一化
        int i=0;
        while(i<nums.length){
            mid[i]=nums[i++];
        }
        return helper(mid,mid.length-1);
    }
    public int helper(int[] nums, int index){
        if(index<0)return 0;
        int max=nums[index];
        if(memo[index]!=-1)return memo[index];
        for(int i = 2;i<=index;i++){//数组的每一项都经此处理
            max = Math.max(max,nums[index]+helper(nums,index-i));//选择最大预约
            memo[index]=max;
        }
        return max;
    }
}
```