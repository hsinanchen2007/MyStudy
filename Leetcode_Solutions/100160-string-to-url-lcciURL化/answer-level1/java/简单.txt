### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        String substring = S.substring(0, length);
        return substring.replace(" ", "%20");
    }
}
```