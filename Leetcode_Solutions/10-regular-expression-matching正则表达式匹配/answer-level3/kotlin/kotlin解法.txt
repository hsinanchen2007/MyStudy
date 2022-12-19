### 解题思路
迭代

### 代码

```kotlin
class Solution {
    fun isMatch(s: String, p: String): Boolean {
        if(p.isEmpty()) return s.isEmpty()
        var firstCheck = !s.isEmpty() && (s.first().equals(p.first()) || p.first().toString().equals("."))
        if(p.length >= 2 && p[1].toString().equals("*")){
            return isMatch(s, p.substring(2)) || firstCheck && isMatch(s.substring(1), p)
        }else{
            return firstCheck && isMatch(s.substring(1), p.substring(1))
        }
    }
}
```