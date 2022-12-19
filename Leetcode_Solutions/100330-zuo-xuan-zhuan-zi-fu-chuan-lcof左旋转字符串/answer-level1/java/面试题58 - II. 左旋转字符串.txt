### 解题思路
直接调用API
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuffer s1 = new StringBuffer(s.substring(0,n));
        StringBuffer s2 = new StringBuffer(s.substring(n,s.length()));
        return new String(s2.append(s1));
    }
}
```