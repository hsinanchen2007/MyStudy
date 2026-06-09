### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpaces(String S,int length) {
        
        if (S==null || length < 0) return null;
        
        return S.substring(0, length).replace(" ", "%20");
    }
}
```