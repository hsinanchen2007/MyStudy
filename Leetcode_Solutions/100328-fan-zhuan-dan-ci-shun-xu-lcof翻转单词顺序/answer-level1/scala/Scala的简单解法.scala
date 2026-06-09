### 解题思路

这个运行时间就很离谱……

![image.png](https://pic.leetcode-cn.com/64f0a595adcca134314f3feb6ec13ca80e8b256b028286066bd02a2a28d46f34-image.png)

第二个方法使用正则一步到位，不过得注意处理两头的空格。两个方法运行时间没差。

### 代码

```scala
object Solution {
    def reverseWords(s: String): String = {
        s.split(" ").filter(_.length != 0).reverse.mkString(" ")
    }

    def reverseWords2(s: String): String = {
        s.trim().split("\\s+").reverse.mkString(" ")
    }
}
```