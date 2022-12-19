### 解题思路
java 贪心算法
1. 遍历字符串，将不重复的字符加入队列
2. 加入当前字符串的时候，从队列尾部判断与当前字符的字典顺序，
3. 如果当前字符小于队列尾部的字符，则从字符串当前位置向后寻找看是否有重复的，如果有，则删除队列尾部字符
4. 按照步骤3遍历队列
5. 如果队列包含当前字符，则continue，因为队列里面的是最小字典序的字符串

### 代码

```java
class Solution {
    public String removeDuplicateLetters(String s) {
        List<Character> charList = new ArrayList<>();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (charList.contains(chars[i])) {
                continue;
            }
            if (!charList.isEmpty()) {
                Character topChar = charList.get(charList.size() - 1);
                while (!charList.isEmpty() && topChar > chars[i] && s.indexOf(topChar, i) != -1) {
                    charList.remove(topChar);
                    if (charList.size() - 1 >= 0) {
                        topChar = charList.get(charList.size() - 1);
                    }
                }
            }
            charList.add(chars[i]);
        }
        char[] chs = new char[charList.size()];
        for (int i = 0; i < charList.size(); i++) {
            chs[i] = charList.get(i);
        }
        return new String(chs);
    }
}
```