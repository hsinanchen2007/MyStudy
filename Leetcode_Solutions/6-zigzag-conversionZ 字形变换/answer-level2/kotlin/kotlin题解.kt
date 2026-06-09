### 解题思路
此处撰写解题思路

### 代码

```kotlin
import kotlin.math.min
class Solution {
    fun convert(s: String, numRows: Int): String {
        if(numRows == 1) return s
        var rows :ArrayList<String> = ArrayList()
        var length = min(numRows, s.length)
        while (length > 0){
            rows.add(String())
            length --
        }
        var rowSign: Boolean = false //决定字符串加入方向的key
        var key: Int = 0  //用于确定插入哪个rows
        for(char in s) {
            rows[key] = rows[key] + char
            if (key == 0 || key == numRows - 1) rowSign = !rowSign
            key += if (rowSign) {
                1
            } else {
                -1
            }
        }
        var end = ""
        for(index in rows){
            end += index
        }
        return end
    }
}
```