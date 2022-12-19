### 解题思路
此处撰写解题思路
使用二分法进行解决
二分法的适用范围为：两段式
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while( l < r){
            int mid = l + (r - l >> 1);
            if(nums[mid] <= nums[nums.length - 1]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
}
```