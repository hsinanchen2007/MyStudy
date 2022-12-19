### 解题思路
之前移动窗口上看到的关于ASCII的思路
就是比较『词汇表』（字符串数组） words每个字符串的字母个数与『字母表』（字符串） chars的字母个数进行比较
如果字符串 的字符个数都小于等于 字母表提供的单词个数, 就通过, 并累加
否则不通过, 忽略进行下一个单词
在判断下一个字符串 需要重置上一个单词的数组
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if (null == words || words.length == 0 || null == chars || chars.length() == 0) {
            return 0;
        }

        int totalWordSum = 0;
        int[] wordTable = new int[26];
        int[] charsTable = new int[26];
        // 用于重置wordTable的数组
        int[] DEFAULT = new int[26];
        char[] charsArray = chars.toCharArray();
        for (char charsVal : charsArray) {
            int index = charsVal - 'a';
            charsTable[index] += 1;
        }
        for (String item : words) {
            if (null == item) {
                continue;
            }
            System.arraycopy(DEFAULT, 0, wordTable, 0, DEFAULT.length);
            char[] array = item.toCharArray();
            for (char wordChar : array) {
                int index = wordChar - 'a';
                wordTable[index] += 1;
            }

            boolean isOwn = true;
            for (int i = 0; i < 26; i++) {
                if(wordTable[i] > charsTable[i]) {
                    isOwn = false;
                    break;
                }
            }

            if (isOwn) {
                totalWordSum += array.length;
            }
        }
        return totalWordSum;
    }
}
```