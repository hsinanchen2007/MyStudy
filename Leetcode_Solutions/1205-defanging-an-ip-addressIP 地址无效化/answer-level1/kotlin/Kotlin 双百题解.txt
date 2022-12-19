![屏幕快照 2019-11-30 下午7.01.03.png](https://pic.leetcode-cn.com/c1f024c46f2873bbe1c39eab6ef4129349627032dc66b27a8e935a6eb19dc09c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-30%20%E4%B8%8B%E5%8D%887.01.03.png)

```
class Solution {
    fun defangIPaddr(address: String): String {
        var a = String()
        for (i in address) {
            if (i == '.') {
                a += '['
                a += '.'
                a += ']'
            } else {
                a += i
            }
        }
        return a
    }
}
```
