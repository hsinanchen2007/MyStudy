### 解题思路
我们定义一个总和currentSum,和一个是否使用过的used数组来做状态管理。
当currentSum==target的时候,就对k减1来获取下一组可以求和等于target的情况。
如果要把所有等于sum/k的子数组找出来，那么就要在currentSum==target的时候，将数字保存进来。

### 代码

```java
class Solution {

    private boolean checkCanPartitionKSubsets(int[] nums,int currentSum,int target,int start,int k,boolean[] used){
        if(k==0){
            return true;
        }
        if(currentSum>target){
            return false;
        }
        if(currentSum==target){
            return checkCanPartitionKSubsets(nums,0,target,0,k-1,used);
        }
        for(int i = start;i<nums.length;i++){
            if(!used[i] && nums[i]+currentSum<=target){
                used[i] = true;
                if(checkCanPartitionKSubsets(nums,nums[i]+currentSum,target,i+1,k,used)){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }

    public boolean canPartitionKSubsets(int[] nums, int k) {
        if(nums==null||nums.length==0){
            return false;
        }
        int sum = Arrays.stream(nums).sum();
        if(sum%k>0){
            return false;
        }
        boolean[] used = new boolean[nums.length];
        int target = sum/k;
        boolean result = checkCanPartitionKSubsets(nums,0,target,0,k,used);
        return result;
    }
}
```