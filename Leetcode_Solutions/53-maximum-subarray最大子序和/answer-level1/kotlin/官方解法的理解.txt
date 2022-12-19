### 分治法解题思路
最大子数组无非三种情况：1、在整个数组的左边，2、在整个数组的右边，3、经过数组的中间，横穿这个数组

### 代码

```kotlin
class Solution {
    fun maxSubArray(nums: IntArray): Int {
        return maxSubArray(nums, 0, nums.size - 1)
    }

    fun maxSubArray(nums: IntArray, left: Int, right: Int): Int {
        if (left == right) {
            return nums[left]
        }
        //1、将问题转化为求左边子数组的最大子数组和、求右边子数组的最大子数组和、求中间子数组的最大子数组和，最后比较三个最大子数组和得到整个的最大子数组和
        val mid = (left + right) / 2
        //2、左边子数组的最大子数组和又可以转化为三个子数组的最大子数组和的比较
        val leftSum = maxSubArray(nums, left, mid)
        val rightSum = maxSubArray(nums, mid + 1, right)
        //3、中间子数组必须包含中间元素，所以不可以转化上面的问题
        val crossSum = crossSum(nums, left, right)
        return Math.max(Math.max(leftSum, rightSum), crossSum)
    }

    fun crossSum(nums: IntArray, left: Int, right: Int): Int {
        if (left == right) {
            return nums[left]
        }
        val mid = (left + right) / 2
        //4、从中间向左累加过程中，存在一个最大值
        var leftSubsum = Integer.MIN_VALUE
        var currSum = 0
        for (i in mid downTo left - 1 + 1) {
            currSum += nums[i]
            leftSubsum = Math.max(leftSubsum, currSum)
        }
        //5、从中间向右累加过程中，存在一个最大值
        var rightSubsum = Integer.MIN_VALUE
        currSum = 0
        for (i in mid + 1 until right + 1) {
            currSum += nums[i]
            rightSubsum = Math.max(rightSubsum, currSum)
        }
        //6、两者相加得到中间子数组的最大子数组和(必须左右相加，因为需要穿过中间的元素)
        return leftSubsum + rightSubsum
    }
}
```
### 贪心法解题思路
贪心法，至当前位置的最佳答案。
但当前元素为负数仍需累加，一是因为如果不累加就与前面一个位置时的最佳答案一样；二是因为方便后面位置的最佳答案计算。

### 代码

```kotlin
class Solution {
    fun maxSubArray(nums: IntArray): Int {
        var curMax = 0
        for (i in nums.indices) {
            if (curMax > 0) {
                nums[i] = nums[i] + curMax
            }
            curMax = nums[i]
        }
        var max = nums[0]
        for (i in nums) {
            if (i > max) {
                max = i
            }
        }
        return max
    }
}
```