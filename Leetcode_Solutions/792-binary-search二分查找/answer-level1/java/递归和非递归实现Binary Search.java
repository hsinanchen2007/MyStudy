明确[循环不变量](https://baike.baidu.com/item/循环不变量/8353186?fr=aladdin)：变量的值可能在变化，但是它的含义是不变的

```
// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
class Solution {
    public int search(int[] nums, int target) {
        // 在[l...r]的范围里寻找target
        int l = 0, r = nums.length - 1;
        while (l <= r) {    // 当 l == r时,区间[l...r]依然是有效的
            //int mid = (l + r)/2;
            // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                // target在[mid+1...r]中; [l...mid]一定没有target
                l = mid + 1;
            } else {// target < arr[mid]
                // target在[l...mid-1]中; [mid...r]一定没有target
                r = mid - 1;
            }
        }
        return -1;
    }
}
```
***
修改循环不变量
```
// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
class Solution {
    public int search(int[] nums, int target) {
        // 在[l...r)的范围里寻找target
        int l = 0, r = nums.length;
        // 当 l == r 时, 区间[l...r)是一个无效区间
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                // target在[mid+1...r)中; [l...mid]一定没有target
                l = mid + 1;
            } else {// target < arr[mid]
                // target在[l...mid)中; [mid...r)一定没有target
                r = mid;
            }
        }
        return -1;
    }
}
```
***
使用递归地方式实现二分查找法 
```
class Solution {
    // 二分查找法,在有序数组arr中,查找target
    // 如果找到target,返回相应的索引index
    // 如果没有找到target,返回-1
    public int search(int[] nums, int target) {
        return search(nums, 0, nums.length - 1, target);
    }
    private int search(int[] nums, int l, int r, int target) {
        if (l > r) {
            return -1;
        }
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return search(nums, l, mid - 1, target);
        } else {
            return search(nums, mid + 1, r, target);
        }
    }
}
```
