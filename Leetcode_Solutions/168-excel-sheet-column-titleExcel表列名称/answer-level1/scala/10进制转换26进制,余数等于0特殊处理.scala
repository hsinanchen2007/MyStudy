
AB= 1×26+2
BB= 2×26+2
ZZ= 26×26+26
实际就是10进制转26进制,但是这里的26进制不是从0开始的
当取余数=0时,可以看到对应于+26的情况,所以要减掉26,才能再做整除,不然除以26以后,所得的商是多1的


```
object Solution {
    def convertToTitle(n: Int): String = {
        var x = n
        val arr = (0 to 25).map(_ + 'A' - 1).map(_.toChar).toArray
        arr(0) = 'Z'
        val stack = scala.collection.mutable.Stack[Char]()
        while (x != 0) {
            val remainder = x % 26
            stack.push(arr(remainder))
            if (remainder == 0) {
                x = x - 26
            }
            x = x / 26
        }
        stack.mkString("")
    }
}
```
