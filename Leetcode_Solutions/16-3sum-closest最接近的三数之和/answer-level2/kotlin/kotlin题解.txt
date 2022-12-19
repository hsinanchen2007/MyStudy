### 解题思路
三指针

### 代码

```kotlin
import kotlin.math.abs
class Solution {
    class result(val key: Int, val value: Int)
    fun threeSumClosest(nums: IntArray, target: Int): Int {
        if(nums.isEmpty()) return 0
        nums.sort()
        var start = 0
        var left = start + 1
        var right = nums.size - 1
        var sum = nums[start] + nums[left] + nums[right]
        val resultArray = arrayListOf(result(abs(target - sum) ,sum))
        while (nums.size - start > 2){
            if(right > left) {
                    when {
                        nums[right] + nums[left] + nums[start] > target -> {
                            sum = nums[start] + nums[left] + nums[right]
                            resultArray.add(result(abs(target - sum) ,sum))
                            right--
                        }
                        nums[right] + nums[left] + nums[start] < target -> {
                            sum = nums[start] + nums[left] + nums[right]
                            resultArray.add(result(abs(target - sum) ,sum))
                            left++
                        }
                        nums[right] + nums[left] + nums[start] == target -> {
                            return target
                        }
                    }
            }else{
                start ++
                left = start + 1
                right = nums.size - 1
            }
        }

        resultArray.sortBy { it.key }
        return resultArray.first().value
    }
}
```