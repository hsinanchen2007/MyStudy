### 解题思路
使用java String内置函数，先进行字符串截取之后进行字符串替换。

### 代码

```java
class Solution {
    public String replaceSpaces(String S, int length) {
        return S.substring(0, length).replaceAll(" ", "%20");
    }
}
```