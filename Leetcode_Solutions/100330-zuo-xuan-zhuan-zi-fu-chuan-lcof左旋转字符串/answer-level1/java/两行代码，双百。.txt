### 解题思路
这类旋转字符串的都是一个套路，只要做过一次之后就有感觉了。

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        int length = s.length();
        return (s + s).substring(n, length + n);
    }
}
```