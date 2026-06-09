### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        char[] bytes = s.toCharArray();
		return new String(bytes, n, s.length() - n) + new String(bytes, 0, n);
    }
}
```