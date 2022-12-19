### 解题思路
二分查找变形题
不断查找-返回低位left即可

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        //二分查找
        if (nums.length < 0) {
            return 0;
        }

        //开始二分查找
        int left    =   0;
        int right   =   nums.length - 1;
        while (left < right) {
            int mid  = (left + right) >> 1;
            if (nums[mid] > nums[mid+1]) {//右区间
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```