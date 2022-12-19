### 解题思路
采用双指针，去查找对应和为s的两个数字

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        int left = 0,right = nums.length-1;
        while(left<right){
            int value = nums[left]+nums[right];
            if(value == target){
                res[0] = nums[left];
                res[1] = nums[right];
                break;
            }else if(value<target){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
}
```