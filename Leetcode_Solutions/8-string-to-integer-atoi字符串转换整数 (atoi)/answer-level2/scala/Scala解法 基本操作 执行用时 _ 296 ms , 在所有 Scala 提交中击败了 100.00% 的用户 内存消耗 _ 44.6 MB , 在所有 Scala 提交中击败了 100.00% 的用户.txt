```
object Solution {
    def myAtoi(str: String): Int = {
        var res = 0L
        var i = 0
        while(i < str.length) {
            if(str.charAt(i) == '-') {
                //取负号后面的元素
                i = i + 1
                while(i<str.length && str.charAt(i)>='0' && str.charAt(i)<='9') {
                    res = res * 10 + (str.charAt(i)-'0')
                    if(res-1 > Int.MaxValue)
                        return Int.MinValue
                    i = i + 1
                }
                res = res*(-1)
                return res.toInt
            }
            else if((str.charAt(i)>='0'&&str.charAt(i)<='9') || str.charAt(i)=='+') {
                //取正数
                if(str.charAt(i)=='+')
                    i = i + 1
                while(i<str.length && str.charAt(i)>='0' && str.charAt(i)<='9') {
                    res = res * 10 + (str.charAt(i)-'0')
                    if(res > Int.MaxValue)
                        return Int.MaxValue
                    i = i + 1
                }
                return res.toInt
            }
            else if(str.charAt(i) == ' ') {
                //continue，没有操作
                i = i + 1
            }
            else {
                return 0
            }
        }
        0
    }
}
```
