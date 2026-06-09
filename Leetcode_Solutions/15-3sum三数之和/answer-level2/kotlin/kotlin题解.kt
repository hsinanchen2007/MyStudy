### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
 fun threeSum(nums: IntArray): List<List<Int>> {
        if(nums.isEmpty()) return listOf()
        //二话不说 先排个序
        nums.sort()
        var start = 0
        var right = nums.size - 1  //右边指针
        var left = 1  //左边指针
        val result = arrayListOf<List<Int>>()
        //处理一下数据后
        if(nums.first() > 0 || nums.last() < 0){
            return listOf()
        }else{
            while(nums.size - start >= 2){
                if(nums.size - start == 2) return result
                if(right > left) {
                    when {
                        nums[right] + nums[left] + nums[start] > 0 -> right--
                        nums[right] + nums[left] + nums[start] < 0 -> left++
                        nums[right] + nums[left] + nums[start] == 0 -> {
                            if(!result.contains(arrayListOf(nums[start], nums[left], nums[right]))) {
                                result.add(arrayListOf(nums[start], nums[left], nums[right]))
                            }
                            right --
                        }
                    }
                }else{
                    start ++
                    left = start + 1
                    right = nums.size - 1
                }
            }
        }
        return listOf()
    }
}
```