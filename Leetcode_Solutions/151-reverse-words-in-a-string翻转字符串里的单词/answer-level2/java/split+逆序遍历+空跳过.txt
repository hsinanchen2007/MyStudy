### 解题思路
先拆分字符串，然后逆序遍历，空格字符跳过。
思路简单清晰，如下~

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        String result = "";
        for (int i = words.length - 1; i >= 0; i--) {
            if (words[i].length() > 0) {
                result += words[i] + " ";
            }
        }
        return result.length() == 0 ? "" : result.substring(0, result.length() - 1);
    }
}
```