### 解题思路
首先将数组进行排序，然后对排序的数组进行二分查找，得到每个元素的位置，该位置即为小于该元素的元素个数。

**注意处理重复元素的情况。**

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ans = new int[nums.length];
        int[] newNums = Arrays.copyOf(nums, nums.length);
        Arrays.sort(newNums);
        for (int i = 0; i < nums.length; i++) {
            ans[i] = binarySearch(newNums, nums[i]);
        }
        return ans;
    }

    private int binarySearch(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```