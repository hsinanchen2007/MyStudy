### 解题思路
嗯 这种写法挺反人类的  

### 代码

```kotlin
class Solution {
    fun myAtoi(str: String): Int {
        Regex("^[\\+\\-]?\\d+").find(str.trim())?.value?.let { it?.toIntOrNull()?.let { return it } ?: return if(it?.contains("-")!!){ Int.MIN_VALUE }else{ Int.MAX_VALUE }} ?: return 0
    }
}
```