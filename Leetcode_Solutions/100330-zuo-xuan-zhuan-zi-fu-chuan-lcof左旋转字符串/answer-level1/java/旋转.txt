### 解题思路
使用了内置api

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        if(s.length() == 0)
            return s;
        
        StringBuilder sb = new StringBuilder();

        sb = sb.append(s.substring(n, s.length()));
        sb = sb.append(s.substring(0, n));

        return sb.toString();
    }
}
```