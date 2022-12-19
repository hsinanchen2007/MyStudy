### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        String tempTail = s.substring(0,n);
        String tempHead = s.substring(n,s.length());
        return tempHead+tempTail; 
    }
}
```