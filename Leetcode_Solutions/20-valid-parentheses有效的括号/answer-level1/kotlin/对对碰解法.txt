### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun isValid(s: String): Boolean {
         var s = s;
    if (s.length % 2 != 0) return false

    while (s.contains("()") || s.contains("[]") || s.contains("{}")) {
        s = s.replace("()", "").replace("[]", "").replace("{}", "")
    }
    return s.isEmpty()
        
    }
}
```

想象一下搓麻将，只要你有，我就敢挺...