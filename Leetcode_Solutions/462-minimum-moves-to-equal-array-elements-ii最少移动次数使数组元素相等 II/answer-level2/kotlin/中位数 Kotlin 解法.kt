原理: 将数组排好序, 然后找到中位数, 求每一个元素与中位数的差值绝对值和.
当数组数目为奇数时, 直接取中间位置的数目, 即 nums[n/2];
当数组数目为偶数时, 中间位置有两个数, 如果两个数目相等, 那么只需求取其中任何一位中位数, 否则的话, 两个分别计算一下差值绝对值和, 选取其中较小的一个差值绝对值和.

执行用时 : 320 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 : 38.5 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    fun minMoves2(nums: IntArray): Int {
        if (nums.size < 2) {
            return 0
        }
        nums.sort()
        val mid = nums.size / 2
        if (nums.size and 1 == 0) {
            val sum2 = nums.map { if (nums[mid - 1] > it) nums[mid - 1] - it else it - nums[mid - 1] }.sum()
            if (nums[mid] == nums[mid - 1]) {
                return sum2
            }
            val sum1 = nums.map { if (nums[mid] > it) nums[mid] - it else it - nums[mid] }.sum()
            return if (sum1 > sum2) sum2 else sum1
        } else {
            return nums.map { if (nums[mid] > it) nums[mid] - it else it - nums[mid] }.sum()
        }
    }
```
