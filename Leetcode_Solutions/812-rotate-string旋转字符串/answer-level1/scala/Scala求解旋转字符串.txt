![截屏2020-02-04下午9.50.24.png](https://pic.leetcode-cn.com/ca4cc7f6393d77ac24a2146482fa000c354d7dc1778aefe14d97e342e3788b13-%E6%88%AA%E5%B1%8F2020-02-04%E4%B8%8B%E5%8D%889.50.24.png)

主要思路：
1、首先需要判断字符串A是否和B字符串相等，因为只有两个字符串相等才有继续判断的可能；
2、使用**concat**将A接到A的结尾，然后判断是否包含B，包含返回true否则返回false。

```
object Solution {
    def rotateString(A: String, B: String): Boolean = {
        if (A.length() != B.length()) return false
        if (A.concat(A).contains(B)) {
            return true
        }
        return false
    }
}
```