### 解题思路
本来这个题，顺势而为如下面所示：

### 代码

```kotlin
class Solution {
    fun getRow(rowIndex: Int): List<Int> {
        var dp = Array<Int>(rowIndex){0}
        dp[0] = 1
        // 从 第 1 行 到 指定行遍历       
        for(i in 1..rowIndex){
            // 从倒数第二个 到 正数第二个 累加，可以思考+验证，正着来为什么不行。
            for(j in （i-1）.downTo(1)){
                dp[j] = dp[j] + dp[j-1]
            }
            println("第${i}行:${dp.toList()}")
        }

        return dp.toList()
    }
}
```
结果：
输入：3
输出：[1,2,1]
看了一下动图，Perfect...

But，打脸比2000的雪来得还早一些

至于如何修改，各位看官Go on...

