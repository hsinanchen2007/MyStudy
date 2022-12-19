### 解题思路
比较简单，超过100%

### 代码

```kotlin
class Solution {
    fun findNumbers(nums: IntArray): Int {
      var count:Int =0
       for (i in nums){
          if (i.toString().length%2==0){
              count++
          }
       }
        return count
    }
}
```