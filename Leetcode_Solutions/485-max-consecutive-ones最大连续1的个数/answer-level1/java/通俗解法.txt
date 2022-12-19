### 解题思路
1. 声明result这个变量————用于统计连续出现1的计数，当不为1时，则清零操作
2. 对于[1, 0, 1, 1, 0, 1]这种情况，最大出现的次数不是在最后，而是在比对的过程中，这就要求我们去保存中间较大的变量；
3. 变量 max 负责 遍历中始终保持 result最大的任务 

### 代码

```kotlin
class Solution {
    fun findMaxConsecutiveOnes(nums: IntArray): Int {
  var result = 0
    var max = 0
    for (num in nums) {
        if (num == 1) {
            result++
            max = Math.max(result, max)
        } else {
            result = 0
        }
    }
    return max       
    }
}
```