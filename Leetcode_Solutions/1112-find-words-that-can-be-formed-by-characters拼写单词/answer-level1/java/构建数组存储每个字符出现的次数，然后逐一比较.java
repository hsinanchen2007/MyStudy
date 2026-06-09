### 解题思路
能拼写出单词，
1要满足需要拼写的单词比给出的字符少或相等。
2每个字符出现的次数要小于等于给出的字符串中出现的次数。
3按照每个字符和‘a’的ascii码差作为角标（小写字母ascii码是连贯的），构建一个单词表和出现次数对应的表。
4如果还需要分辨大小写的字符的话，数组就不是很适用，可以用hash表来做匹配。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
         Integer size = 0;
        //先解析chars
        int[] charsCount = new int[26];
        char[] chars1 = chars.toCharArray();
        for (char c : chars1) {
            //判断字符的下标，统计每个字符出现的次数
            charsCount[c - 'a']++;
        }

        // 解析word
        for (String word : words) {
            if (word.length() > chars.length()) {
                continue;
            }
            char[] chars2 = word.toCharArray();
            int[] wordChar = new int[26];
            for (char c : chars2) {
                wordChar[c-'a'] ++;
            }
            boolean add = true;
            for (int i = 0; i < wordChar.length; i++) {
                if (charsCount[i] < wordChar[i]) {
                    add = false;
                    break;
                }
            }
            if (add) {
                System.out.println(word);
                size += word.length();
            }
        }
        return size;
    }
}
```