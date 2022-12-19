### 解题思路
比较暴力

### 代码

```kotlin
class Solution {
fun longestCommonPrefix(strs: Array<String>): String {
    var comm:String = ""
    if(strs.size>1){
    var min:Int = strs[0].length
    for (i in strs) if(i.length < min) min=i.length
    if (min==0) return ""
    var count:Int = 0
    out@  for (n in 0 until min) {
        count = 0
        for (m in 1 until strs.size) {
            if (strs[m][n] == strs[m-1][n]) {
               count++
            } else break@out
        }
        if (count==strs.size-1) {
            comm+=strs[count][n]
            }
    }
    }
    if(strs.size==1) comm=strs[0]
    return comm
}}
```