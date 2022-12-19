### 解题思路
物有本末，事有终始，知所先后，则近道矣...

根据题意：我们可以将罗马数字对应的转成阿拉伯数字单位。
需要我们注意的是:
1.我们要先将“双字母”先替换掉(replace())，这样就无需考虑特殊情况啦。
2.按顺序将罗马字母转换为阿拉伯数字即可(无需替换)；
PS:下面的代码为了理解起来方便，所以直接统一来处理啦。


### 代码

```kotlin
class Solution {
    fun romanToInt(s: String): Int {
     var s = s
    var sum = 0
    val array = arrayOf("CM","CD",  "XC",  "XL",  "IX", "IV", "M","D","C","L","X","V","I")
    val intValueArray = intArrayOf(900,400,90,40,9,4,1000,500,100,50,10,5,1)
    while (s.isNotEmpty()) {
        
        for (i in 0 until array.size) {
            val unit = array[i]
            if (s.contains(unit)) {
                sum += intValueArray[i]
                s = s.replaceFirst(unit, "")
            }
        }
    }

    return sum
    }
}
```