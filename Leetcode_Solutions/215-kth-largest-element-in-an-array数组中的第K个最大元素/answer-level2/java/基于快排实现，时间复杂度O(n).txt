思路如下，每次排序将大于基准值key的放key的左边，将小于基准值key的放key的右边。
然后如果基准值所在的位置正好=k-1.则正好就是这个值
如果左边的数量<k-1,则说明要找的数在右边，否则在左边。

```
public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length < k) {
            return 0;
        }
        return find(nums, 0, nums.length - 1, k);
    }

    //逆排序
    private int find(int[] nums, int left, int right, int k) {
        int start = left;
        int end = right;
        int key = nums[start];

        while (start < end) {
            while (start < end && nums[end] <= key) {
                end--;
            }
            nums[start] = nums[end];
            while (start < end && nums[start] >= key) {
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = key;

        if (start == k - 1) {
            return key;
        }
        //比key大的个数少于k-1个，去后半部分找
        if (start < k - 1) {
            return find(nums, start + 1, right, k );
        }
        return find(nums, left, start - 1, k);

    }
```
## [更多leetcode题解参考此处](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)
