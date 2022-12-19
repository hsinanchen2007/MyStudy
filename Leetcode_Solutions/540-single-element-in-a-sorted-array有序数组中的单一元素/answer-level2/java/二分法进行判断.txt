### 解题思路
二分法的对数组的分割标准不一定是大小关系, 本题中, 在目标元素的之前的元素 :下标 m (假设为偶数), nums[m] == nums[m + 1];
但是在目标元素后面的元素, nums[m] != nums[m + 1], 这就是区分目标在前半部分和后半部分的标准.
因为数组是有序的, 如果某个元素出现两次, 那么这两个元素一定是相邻的; 
这里因为 nums[m] != nums[m + 1], 即对目标区间的右边界的变换时, 是无法区别下标 m 对应的数是否是目标元素, 因为非目标元素也是满足的, 所以 r = m (而不是 r = m - 2), 所以 while 中的条件也变了 (不是 l <= r 而是 l < r)

### 代码

```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length, l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l)/2;
            if (m % 2 == 1) {
                m--;
            }
            if(nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                r = m;
            }
        }
        return nums[r];
    }
}
```