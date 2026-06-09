### 解题思路
因为数组有序，所以左右指针相加和target相比就可以确定两个数和为s

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        if(nums==null||nums.length==0){
            return new int[]{};
        }
        int left=0;
        int right=nums.length-1;
        while(left<right){
            int temp=nums[left]+nums[right];
            if(temp>target){
                right--;
            }else if(temp<target){
                left++;
            }else{
                return new int[]{nums[left],nums[right]};
            }
        }
        return new int[]{};
    }
}
```