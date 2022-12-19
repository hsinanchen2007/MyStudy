二分查找旋转数组中的目标数，每次先比较头中尾是否为目标数
之后根据数组的3个位置的大小关系推出下一步应该查找的范围
```
class Solution {
    public boolean search(int[] nums, int target) {
        int i=0;
        int j=nums.length-1;
        while(i<=j){
            int m = i+(j-i)/2; 
            if(nums[i] == target) return true;
            if(nums[j] == target) return true;
            if(nums[m] == target) return true;
            if(nums[i] == nums[m]){
                i++;
                continue;
            }
            if(nums[i] < nums[m]){
                if(nums[i] < target && nums[m] > target){
                    j = m-1;
                    continue;
                }else{
                    i = m+1;
                    continue;
                }
            }else{
                if(nums[m] < target && nums[j] > target ){
                    i = m+1;
                    continue;
                }else{
                    j = m-1;
                    continue;
                }
            }

        }

        return false;
    }

   

}
```
