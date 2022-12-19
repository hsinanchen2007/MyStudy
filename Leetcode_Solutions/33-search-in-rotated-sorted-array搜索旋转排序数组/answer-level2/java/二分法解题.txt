### 解题思路
用二分法，查找目标值。
每次用mid分割，用curr=nums[mid]匹配target,相等就是答案。不等，判断分割后选择往左还是往右。需要根据curr的位置判断走向。当前curr所在的区域分两种 【升序】和【夹着旋转点】
【升序】：必定是start<end ，若curr>target 那target肯定在左边，goleft，反之goright
【夹着旋转点】：分两种情况mid在【大块】或【小块】(如[4,5,6,0,1,2]，那么【大块】就是[4,5,6],【小块】就是[0,1,2],【大块】一定在【小块】前面，否则就是【升序】)；
【mid在小块】:若 tartget在 curr-end之间 (target > curr && target <= nums[end]) goright，反之goleft
【mid在大块】:若 tartget在 start-curr之间（target < curr && target >= nums[start]） goleft，反之goright

大体思路就是这样，接下来判断一些异常情况，调试几次就OK了


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
         if (nums.length == 0) return -1;
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {
            //判断少于三个元素的情况
            if (start == end) return target == nums[start] ? start : -1;
            if (end - start == 1) {
                if (target == nums[end]) return end;
                if (target == nums[start]) return start;
            }
            int mid = (end + start) / 2;
            int curr = nums[mid];
            if (curr == target) return mid;
            boolean goLeft = true;
            if (nums[start] < nums[end]) {
                // 正序
                goLeft = curr>target;
            } else {
                // 夹着反转点
                if (curr < nums[end]) {
                    // 夹在小
                    goLeft = !(target > curr && target <= nums[end]);//goRight取反
                } else {
                    // 夹在大
                    goLeft = (target < curr && target >= nums[start]);
                }
            }
            if(goLeft) {
                //-1+1可以去掉mid这个点
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return -1;
    }
}
```