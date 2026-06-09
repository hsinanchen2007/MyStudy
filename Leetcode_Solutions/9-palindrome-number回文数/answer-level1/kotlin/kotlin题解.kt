### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun isPalindrome(x: Int): Boolean {
        val str: String = x.toString()
        if(str.contains("-") || (x % 10 == 0 && x != 0)) return false
        var backNum = 0
        var y = x
        while (y > backNum){
            backNum = y % 10 + backNum  * 10
            y /= 10
        }
        return y == backNum || y == backNum / 10
    }
}
```