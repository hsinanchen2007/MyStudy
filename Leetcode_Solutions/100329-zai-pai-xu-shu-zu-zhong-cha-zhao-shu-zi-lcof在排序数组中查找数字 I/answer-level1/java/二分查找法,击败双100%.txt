### 解题思路
![image.png](https://pic.leetcode-cn.com/3fe52e9a81898e17ca1bb3f989ca6fb74b797d71e66fbdc81d41e5e25c8965f1-image.png)

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int i = 0 , j = nums.length-1;
        //找右边界
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] <= target){
                i = mid+1;
            }else{ //nums[mid] > target,nums[mid]严格大于target,nums[mid]及其右边都不可能是右边界
                j = mid-1;
            }
        }
        int right = i;//注意,右边界是从左边开始找的
        i = 0 ; j = nums.length-1; //还原i,j
        //找左边界
        while(i<=j){
            int mid = i + (j-i)/2;
            if(nums[mid] >= target){
                j = mid-1;
            }else{ //nums[mid] < target,nums[mid]严格小于target,nums[mid]及其左边都不可能是左边界
                i = mid+1;
            }
        }
        int left = j;//注意,左边界是从右边开始找的
        return right-left-1;
    }
}
```