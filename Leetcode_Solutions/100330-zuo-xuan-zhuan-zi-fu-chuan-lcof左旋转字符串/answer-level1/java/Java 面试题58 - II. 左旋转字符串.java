### 解题思路
1. 直接利用字符串的`subString()`方法将字符串阶段后拼接；

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        int size = s.length();
		return s.substring(n, size) + s.substring(0, n);
    }
}
```