### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun reverse(x: Int): Int {
        var num = x
        var rev = 0
        while(num != 0){
            var pop = num % 10
            num /= 10
            if(rev > Int.MAX_VALUE / 10 || ( rev == Int.MAX_VALUE / 10 && pop > 7)) return 0
            if(rev < Int.MIN_VALUE / 10 || ( rev * 10 == Int.MIN_VALUE / 10 && pop < -8)) return 0
            rev = rev * 10 + pop
        }
        return rev
    }
}
```