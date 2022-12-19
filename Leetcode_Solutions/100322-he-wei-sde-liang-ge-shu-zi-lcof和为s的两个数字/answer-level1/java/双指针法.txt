### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int [] res = new int[2];
        while(left < right){
            if(nums[left] + nums[right] == target){
                res[0] = nums[left];
                res[1] = nums[right];
                //这里要及时返回，否则会陷入死循环。因为一旦匹配
                return res;
            }else if(nums[left] + nums[right] > target){
                right --;
            }else{
                left ++;
            }
        }
        return res;
    }
}
```