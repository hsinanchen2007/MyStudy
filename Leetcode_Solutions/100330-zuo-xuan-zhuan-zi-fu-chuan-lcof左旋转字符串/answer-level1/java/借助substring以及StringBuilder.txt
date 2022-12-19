### 解题思路
借助substring以及StringBuilder
### 代码
```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        StringBuilder sb = new StringBuilder();
        String pre = s.substring(0,n);
        sb.append(s.substring(n,s.length())).append(pre);
        return sb.toString();
    }
}
```