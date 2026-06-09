
对于形如    [3，4，5，1，2] 即`left[0] <= right[0]`
if `left[0] <= target && target < right[0]` 去左边找；else 去右边；

对于形如    [5，1，2，3，4] 即`left[0] > right[0]`
if `right[0] < target && target <= right[right.length-1]` 去右边找； else 去左边；

以下代码块，总感觉有点蠢=。=


```
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int point = nums.length-1;  // 指针指向尾部
        return helpSearch(nums, target, point, false);
    }

    // goRight 判断递归前是 left子组 还是 right子组
    int helpSearch(int[] nums, int target, int point, boolean goRight) {
        int[] left = Arrays.copyOfRange(nums,0,nums.length/2);
        int[] right = Arrays.copyOfRange(nums, nums.length/2, nums.length);

        // 移动指针，指向 left[-1] 在 nums 中的位置
        if (goRight) point = point + left.length;
        else point = point - right.length;

        // 判断 left[-1] 和 right[0] 是否是 taget
        if (right[0] == target) return point+1;
        if (left.length != 0 && left[left.length-1] == target) return point;

        // 长度大于1的子组才进行递归，从有序子组中寻找 taget
        if ((left.length > 1 || right.length > 1) && left[0] <= right[0]) {
            if (left[0] <= target && target < right[0]) {
                if (left.length > 1) return helpSearch(left, target, point, false);
            } else {
                if (right.length > 1)return helpSearch(right, target, point, true);
            }
        } else {
            if (right[0] < target && target <= right[right.length-1]) {
                if (right.length > 1) return helpSearch(right, target, point, true);
            } else {
                if (left.length > 1) return helpSearch(left, target, point, false);
            }
        }

        return -1;
    }
}
```
