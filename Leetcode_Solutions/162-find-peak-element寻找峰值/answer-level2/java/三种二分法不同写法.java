### 解题思路
2020 春节假期无聊，故将二分查找的三种模版全部用到这一题中，仅供参考。

### 代码

```java
class Solution {

    // 模版一：查找单个索引
    public int findPeakElement(int[] nums) {
        int lo = 0;
        int hi = nums.length - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // 0
            long pre = mid - 1 < 0 ? -Long.MAX_VALUE : nums[mid - 1];
            long cur = nums[mid];
            long next = mid + 1 > hi ? -Long.MAX_VALUE : nums[mid + 1];

            if (pre < cur && cur > next) {
                return mid;
            }

            if (pre < cur) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }


    // 模版二：查找单个索引及其右邻居
    public int findPeakElement(int[] nums) {
        int lo = 0;
        int hi = nums.length - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid + 1]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    // 模版三：查找当前索引及其左右邻居
    public int findPeakElement(int[] nums) {
        int lo = 0;
        int hi = nums.length - 1;

        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid + 1]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // post process
        if (lo < hi  && nums[lo] < nums[hi]) {
            return hi;
        } else {
            return lo;
        }
    }
}
```