### 解题思路

1. 最外层遍历 loop1：单词表中的每一个单词；
2. loop1：将当前单词和字母表分别转换成一个 char[] 数组便于比较；
3. loop1：将字母表转为一个 list 便于删除；
4. 在 loop1 中，遍历当前单词的每一个字符（字母）loop2。关键变量 matchWord 用于存储当前单词是否匹配；
5. loop2：检查当前单词的当前字符在单词表中是否存在。关键变量 getToYou 用户存储当前字符是否匹配；
6. loop2：遍历字母表的时候，如果当前字符匹配，删除字母表的当前字符，游标从头开始；

### 代码

```java
class Solution {
    // 输入：words = ["cat","bt","hat","tree"], chars = "atach"
    public int countCharacters(String[] words, String chars) {
        int count = 0;
        int length = words.length;

        // 遍历每一个单词
        for (int i = 0; i < length && length <= 1000; i++) { // 【loop1】
            char[] currentWordChars = words[i].toCharArray();
            char[] optionalChars = chars.toCharArray();

            // 字母表由数组转 list 便于迭代删除
            ArrayList<Character> list = new ArrayList<>();
            for (char c : optionalChars) {
                list.add(c);
            }
            Iterator<Character> it = list.iterator();

            // 遍历当前单词的每一个字符
            boolean matchWord = false;
            for (int j = 0; j < currentWordChars.length; j++) { // 【loop2】
                char currentWordChar = currentWordChars[j];
                matchWord = false;
                // 找字母
                boolean getToYou = false;
                while (it.hasNext()) {
                    Character character = it.next();
                    if (character == currentWordChar) {
                        getToYou = true;
                        matchWord = true;
                        it.remove();
                        it = list.iterator();
                        break;
                    }
                }
                if (!getToYou) {
                    break;
                }
            }

            if (matchWord) {
                count += currentWordChars.length;
            }
        }
        return count;
    }
}
```