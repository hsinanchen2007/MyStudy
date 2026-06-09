### 解题思路
left和right放两头,求和小于target，说明left++，反之right--

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        if(nums == null) return res;
        int left = 0,right = nums.length - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                res[0] = nums[left];
                res[1] = nums[right];
                return res;
            }else{
                if(sum > target) right--;
                if(sum < target) left++;
            }
        }
        return res;
    }
}
```