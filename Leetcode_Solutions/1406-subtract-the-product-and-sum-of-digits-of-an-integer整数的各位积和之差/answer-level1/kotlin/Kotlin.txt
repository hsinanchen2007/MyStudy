### 解题思路
执行时间168ms，惨不忍睹
内存消耗击败100%

### 代码

```kotlin
class Solution {
fun subtractProductAndSum(n: Int): Int {
    var str:String = n.toString()
    var product:Int = 1
    var sum:Int = 0
    for (i in str){
        product *= i.toString().toInt()
        sum += i.toString().toInt()
    }
    return product-sum
}
}
```