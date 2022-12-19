### 解题思路
当 str1+str2 != str2+str1 时才能有解
找最大公约数可以看成对两个字符串的长度取最大公约数，然后从0截取最大公约数长度的串

### 代码

```kotlin
class Solution {
fun gcdOfStrings(str1: String, str2: String): String {
    if (str1 + str2 != str2 + str1) return ""
    return str1.substring(0, betterGCD(str1.length, str2.length))
}

fun gcd(a: Int, b: Int): Int { //辗转相除法(取余运算性能较差)
    return if (a % b == 0) {
        b
    } else {
        gcd(b, a % b)
    }
}

/*
and 如果对应位都是1，则结果为1，否则为0
or 如果对应位都是0，则结果为0，否则为1
xor 如果对应位值相同，则结果为0，否则为1
inv 按位翻转操作数的每一位，即0变成1，1变成0
shl 按位左移指定的位数，相当于乘以2的N次方。移掉的省略，右边缺失的位，用0补齐
shr 按位右移指定的位数，相当于除以2的N次方，移掉的省略，左边缺失的位，如果是正数则补0，若为负数，可能补0或补1，这取决于所用的计算机系统
ushr 按位右移指定的位数，移掉的省略，左边缺失的位，用0补齐
 */
fun betterGCD(a: Int, b: Int): Int { //
    var len1 = a
    var len2 = b
    while (len2 != 0) {
        len1 %= len2
        len1 = len1 xor len2
        len2 = len2 xor len1
        len1 = len1 xor len2
    }
    return len1
}
}
```