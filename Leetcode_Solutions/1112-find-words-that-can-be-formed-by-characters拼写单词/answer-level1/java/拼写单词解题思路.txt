### 解题思路
思路：
1. 利用字母表的26个字母从小写的a～z，计算每个单词的字母个数
2. 将字母表和每个单词都转换为数组，计算每个字母的个数
2. 比较每个单词的字母个数不能超过字母列表中的每个字母个数
3. 将符合条件2的单词长度进行累加

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int countLength = 0;
        int[] charInts = count(chars);
        
        for(String word : words) {
            int[] wordInts = count(word);
            if (containsArray(wordInts, charInts)) {
                countLength += word.length();
            }
        }
        return countLength;
    }

    // 比较单词的每个字母个数不能大于字母表中每个字母的个数
    private boolean containsArray(int[] wordInts, int[] charInts) {
        boolean isContains = true;
        for(int i=0;i < wordInts.length; i ++) {
            if (wordInts[i] > charInts[i]) {
                isContains = false;
                break;
            }
        }
        return isContains;
    }

    // 计算单词中的字母个数
    private int[] count(String str) {
        int[] chars = new int[26];
        char[] strChars = str.toCharArray();
        for(char c : strChars) {
            chars[c - 'a']++;
        }
        return chars;
    }
}
```