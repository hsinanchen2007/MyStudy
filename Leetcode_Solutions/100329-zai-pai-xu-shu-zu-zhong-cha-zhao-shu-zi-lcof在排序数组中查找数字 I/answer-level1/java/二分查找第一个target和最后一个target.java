### 解题思路
二分查找第一个target和最后一个target
res = end-start+1;

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length==0) return 0;
        int start = findFirst(nums, target);
        int end = findLast(nums, target);
        if (start==-1||end==-1) return 0;
        int res = end-start+1;
        return res;
    }
    int findFirst(int[] nums, int target) {
        int p = 0, q=nums.length-1;
        while (p<q-1) {
            int mid = p+(q-p)/2;
            if(nums[mid]>=target) { //在前面
                q = mid;
            } else {
                p = mid+1;
            }
        }
        return nums[p]==target?p:nums[q]==target?q:-1;
    }
    int findLast(int[] nums, int target) {
        int p = 0, q=nums.length-1;
        while (p<q-1) {
            int mid = p+(q-p)/2;
            if(nums[mid]>target) { //在前面
                q = mid-1;
            } else {
                p = mid; //注意死循环
            }
        }
        return nums[q]==target?q:nums[p]==target?p:-1;
    }
}
```
![image.png](https://pic.leetcode-cn.com/7634050635ddaaa5b554e1e6ac6d2c1deed80e7a8b044c6c8f4de9a603f58837-image.png)
