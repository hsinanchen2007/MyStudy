### 解题思路
采用二分查找，如果nums[mid]!=mid,说明0-mid之间缺失正数，反之mid~end之间缺失正数
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        if(nums==null||nums.length==0)return 0;
        int left = 0,right = nums.length;
        while(left<right){
            int mid = (right + left)/2;
            if(nums[mid]!=mid){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
}
```