### 解题思路
水题一道，感觉没啥好说的，注意循环中保持各种指针性质不变即可。另外就是要注意最后一个字符的边界情况，可以向char数组添加一个0字符来处理这种情况，或者就把代码复制一遍，在循环外再强行执行一次。

唯一难点在于题目要求空间复杂度为O(1)，也就是不能在解中使用数组之类的玩意儿，修改也必须是在原地修改。

那么我感觉难点主要就是如何使用O(1)空间复杂度的内存来把整数写成十进制字符数组。

### 使用取余运算来把数字变换成字符串

有如下结论：
1. 对于一个n进制整数k来说，
    > f(k) = k % n

    可以取得该进制下的末位数字，例如对于10进制整数123来说，123 % 10 = 3即123在10进制下的末位。
2. 对于一个n进制整数k来说，
    > f(k) = k / n

    可以取得该进制下除去末尾的高位数字。例如对于10进制整数123来说，123 / 10 = 12即123在10进制下去掉末位的高位。

反复交替执行上述两个运算，直到k = 0为止，即可逆序输出k的各个数位。

如果你像我一样懒得在原地Reverse的话，可以先求出k有多少位，直接把指针指向末尾，然后挨着往前写即可解决逆序输出的问题。除了把数字复制一下，预先执行一遍计算有多少位这种O(n)时间复杂度的算法之外，其实我们可以直接用对数函数来直接计算出一个整数有多少位，公式如下：
> f(k) = floor(log10(k)) + 1

其中log10是以10为底的对数，floor表示向下取整。

### 代码

```kotlin
import kotlin.math.floor
import kotlin.math.log10

class Solution {
    fun compress(chars: CharArray): Int {
        var charCursor = 0
        var sizeCursor: Int
        var currentChar = chars[0]
        var currentSize = 0

        for (i in chars.indices) {
            if (chars[i] != currentChar) {
                //Write last
                if (currentSize > 1) {
                    chars[charCursor] = currentChar
                    sizeCursor = charCursor + floor(log10(currentSize.toDouble())).toInt() + 1
                    charCursor = sizeCursor + 1
                    while (currentSize != 0) {
                        chars[sizeCursor--] = '0' + currentSize % 10
                        currentSize /= 10
                    }
                } else {
                    chars[charCursor++] = currentChar
                    currentSize = 0
                }


                //Prepare for next iteration
                currentChar = chars[i]
            }
            currentSize++
        }
        if (currentSize > 1) {
            chars[charCursor] = currentChar
            sizeCursor = charCursor + floor(log10(currentSize.toDouble())).toInt() + 1
            charCursor = sizeCursor + 1
            while (currentSize != 0) {
                chars[sizeCursor--] = '0' + currentSize % 10
                currentSize /= 10
            }
        } else {
            chars[charCursor++] = currentChar
        }
        return charCursor
    }
}
```