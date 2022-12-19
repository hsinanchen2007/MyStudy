### 解题思路
此处撰写解题思路
感谢题目中提供的图。
一层一层算，计算每层的山头之间的空格数
### 代码

```kotlin
class Solution {
    fun trap(height: IntArray): Int {
        var biggest = 0
        var result = 0
        height.forEach {
            if (it > biggest)
                biggest = it
        }
        result = anotherTrap(height, biggest)

        return result
    }
    fun anotherTrap(height: IntArray, num:Int):Int{
        if (num == 0) {
            return 0
        }

        var count = 0
        var index = -1
        for (i in height.indices) {
            if (height[i] >= num) {
                if (index == -1){
                    index = i
                    continue
                }
                count += i - index - 1
                index = i
            }
        }
        return count + anotherTrap(height, num - 1)
    }
}
```