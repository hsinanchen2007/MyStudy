### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        int[] nums2 = new int[nums.length + 2];
        int n = nums2.length;
        nums2[0] = Integer.MIN_VALUE;
        nums2[n - 1] = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            nums2[i + 1] = nums[i];
        }
        int start = 1, end = n - 2;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums2[mid] < nums2[mid - 1]) {
                end = mid;
            } else if (nums2[mid] < nums2[mid + 1]) {
                start = mid;
            } else {
                start = mid;
            }
        }
        
        if(nums2[start] > nums2[end]) {
            return start - 1;
        } else {
            return end - 1;
        }
    }
}
```