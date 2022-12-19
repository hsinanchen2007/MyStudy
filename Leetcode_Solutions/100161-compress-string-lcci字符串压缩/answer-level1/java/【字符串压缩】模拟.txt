### 解题思路
直接模拟就行了：遍历整个字符串，用两个变量分别维护**连续字符**和**连续字符的数量**，最后拼接在一起就OK了。

### 代码

```java
class Solution {
    public String compressString(String S) {
        if (S == null || S.length() <= 2) {
            return S;
        }
        StringBuilder compressStrBuilder = new StringBuilder();
        char previousChar = S.charAt(0);
        int previousCharCount = 1;
        for (int i = 1; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == previousChar) {
                previousCharCount++;
            } else {
                compressStrBuilder.append(previousChar).append(previousCharCount);
                previousChar = c;
                previousCharCount = 1;
            }
        }
        compressStrBuilder.append(previousChar).append(previousCharCount);
        if (compressStrBuilder.toString().length() >= S.length()) {
            return S;
        }
        return compressStrBuilder.toString();
    }
}
```