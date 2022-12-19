### 解题思路
此处采用Set 去重，若有重复，则Set的size必然 小于原来的长度...
PS: 浪费空间
### 代码

```kotlin
class Solution {
    fun containsDuplicate(nums: IntArray): Boolean {
         val set = hashSetOf<Int>()
        for (n in nums){
            set.add(n)
        }
        return nums.size != set.size
    }
}
```