### 解题思路
执行用时 :
196 ms
, 在所有 kotlin 提交中击败了
100.00%
的用户
内存消耗 :
33.7 MB
, 在所有 kotlin 提交中击败了
66.67%

### 代码

```kotlin
class Solution {
fun uniqueMorseRepresentations(words: Array<String>): Int {
    val morse:Array<String> = arrayOf(".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..")
    var count1:Int = 0
    for (m in words.indices){
        var a:String = ""
        for (n in words[m]) {
            a += morse[n.toInt() - 97]
        }
        var count2:Int = 0
        for (j in words){
            if (a == j) count2++
        }
        if(count2 == 0) count1++
        words[m] = a
    }
    return count1
}
}
```