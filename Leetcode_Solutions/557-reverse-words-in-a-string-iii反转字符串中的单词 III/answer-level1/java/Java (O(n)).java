### 解题思路
使用StringBuilder优化速度。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++){
            sb.append(reverseWord(words[i]) + " ");
        }
        return sb.toString().trim();
    }

    public String reverseWord(String s){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++){
            sb.insert(0, s.charAt(i));
        }
        return sb.toString();
    }
}
```