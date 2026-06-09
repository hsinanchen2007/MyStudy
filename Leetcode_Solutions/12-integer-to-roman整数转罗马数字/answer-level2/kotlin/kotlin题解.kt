### 解题思路
转换成对照表去解决  实际情况下这个方法看上去不那么睿智

### 代码

```kotlin
class Solution {
    fun intToRoman(num: Int): String {
        //输入确保在 1 到 3999 的范围内
        val nums = intArrayOf(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        val romans = arrayOf("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I")
        var index = 0
        var end = ""
        var cloneNum = num
        while (index < nums.size){
            while (cloneNum >= nums[index]){
                end += romans[index]
                cloneNum -= nums[index]
            }
            index ++
        }
        return end
    }
}
```