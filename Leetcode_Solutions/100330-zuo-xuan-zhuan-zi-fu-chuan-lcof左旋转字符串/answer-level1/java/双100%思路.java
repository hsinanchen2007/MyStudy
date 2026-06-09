### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
     s=s.substring(n,s.length())+s.substring(0,n);
     return s;    }
}
```