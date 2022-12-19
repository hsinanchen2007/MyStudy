### 解题思路
用数组保存每个位置的数字，再循环一半的数组判断与另一半是否相等，缺点是不能判断负数。

### 代码

```kotlin
class Solution {
    fun isPalindrome(x: Int): Boolean {
         if (x<0)
            return false
        val array = arrayOfNulls<Int>(10)
        var temp = x
        var index = 0
        while (temp != 0) {
            array[index] = temp.rem(10)
            index += 1
            temp /= 10
        }
        val noNullArray = array.filterNotNull()
        (0 until noNullArray.size.div(2))
                .forEach {
                    if (noNullArray[it] != noNullArray[noNullArray.size - 1 - it])
                        return false
                }
        return true
    }
}
```