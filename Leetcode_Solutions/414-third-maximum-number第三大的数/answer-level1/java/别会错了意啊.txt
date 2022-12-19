### 解题思路

一定要读清题意，别会错了意啊...

其它需要注意的是：
1. 大家可能都知道使用Set去重；
2. Set是无序的...

### 代码

```kotlin
class Solution {
    fun thirdMax(nums: IntArray): Int {
    val set = HashSet<Int>()
    
    for (n in nums){
        set.add(n)
    }

    val index = if (set.size > 2) 2 else 0
    return set.toList().sortedDescending()[index]
}
}
```