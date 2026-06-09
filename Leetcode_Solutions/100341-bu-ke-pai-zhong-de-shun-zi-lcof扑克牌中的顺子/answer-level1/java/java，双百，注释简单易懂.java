```
class Solution {
    fun isStraight(nums: IntArray): Boolean {
        /** 排除存在重复数字的情况，因为除了0以外的重复，就不可能是顺子 */
        val set = hashSetOf<Int>()
        for (i in 0 until nums.size) {
            if (nums[i] == 0 ) {
                continue
            }
            if (set.contains(nums[i])) {
                return false
            } else {
                set.add(nums[i])
            }
        }

         /** 没有重复数字的情况下，只需要计算最大最小值的差是不是小于5 */
        var max = Int.MIN_VALUE
        var min = Int.MAX_VALUE
        for (i in 0 until nums.size) {
            if (nums[i] != 0) {
                max = Math.max(max, nums[i])
                min = Math.min(min, nums[i])
            }
        }
        
        return max - min <= 4
    }
}
```
