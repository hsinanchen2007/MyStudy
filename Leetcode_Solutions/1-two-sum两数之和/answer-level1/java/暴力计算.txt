### 解题思路
暴力法：遍历每个元素 xx，并查找是否存在一个值与 target − x 相等的目标元素

### 代码


class Solution {
    public int[] twoSum(int[] nums, int target) {
         for(int i = 0;i<nums.length-1 ;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i] == target-nums[j]){
                    return new int[]{i,j};
                }
            }
        }
        return null;
    }
}
```