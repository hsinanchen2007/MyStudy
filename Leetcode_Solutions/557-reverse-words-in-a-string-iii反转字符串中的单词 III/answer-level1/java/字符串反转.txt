### 解题思路
先将长字符串根据空格分割，再反转每一个单词，使用 Stringbuilder 提高效率，比较 general 的做法

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) return s;
        // 根据空格分割数组
        String[] words = s.split(" ");
        // 反转单词
        StringBuilder ans = new StringBuilder();
        for (String word: words){
            StringBuilder temp = new StringBuilder();
            for (int i = word.length() - 1; i >= 0; i--) {
                temp.append(word.charAt(i));
            }
            ans.append(temp);
            ans.append(" ");
        }
        return ans.toString().trim();
    }
}
```