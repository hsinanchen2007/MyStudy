## 方法一：暴力匹配
### 解题思路
* 三层for遍历每个单词到字母表匹配

### 代码
```java
    public int countCharacters(String[] words, String chars) {
        char[] table = chars.toCharArray();
        int tableLen = table.length, wordLen, sum = 0, i;
        boolean[] used = new boolean[tableLen];
        for (String word : words) {
            Arrays.fill(used, false);
            wordLen = word.length();
            for (i = 0; i < wordLen; i++) {
                int idx = contains(table, tableLen, used, word.charAt(i));
                if (idx == -1) break;
                used[idx] = true;
            }
            if (i == wordLen) sum += wordLen;
        }
        return sum;
    }

    private int contains(char[] table, int tableLen, boolean[] used, char target) {
        for (int i = 0; i < tableLen; i++)
            if (!used[i] && table[i] == target)
                return i;
        return -1;
    }
```

## 方法二: 字典法
### 解题思路
* 使用Map字典把字母和数量存进去，循环对比词汇表中单词，重点是对比字母和数量，而不是逐一对比字母。

### 代码
```java
   public int countCharacters(String[] words, String chars) {
        Map<Character, Integer> charsCnt = new HashMap<>();
        for (char c : chars.toCharArray()) {
            if (charsCnt.containsKey(c)) charsCnt.put(c, charsCnt.get(c) + 1);
            else charsCnt.put(c, 1);
        }
        Map<Character, Integer> wordCnt;
        int ans = 0;
        for (String word : words) {
            wordCnt = new HashMap<>();
            for (char c : word.toCharArray()) {
                if (wordCnt.containsKey(c)) wordCnt.put(c, wordCnt.get(c) + 1);
                else wordCnt.put(c, 1);
            }
            boolean isAns = true;
            for (char c : word.toCharArray())
                if (charsCnt.getOrDefault(c, 0) < wordCnt.getOrDefault(c, 0)) {
                    isAns = false;
                    break;
                }
            if (isAns) ans += word.length();
        }
        return ans;
    }
```

## 方法三: 提前构建字母表缓存数组 + 回溯思想
### 解题思路
1. 提前构建一个26个字母大小的int[]数组存放字母表里的字母和数量
2. 循环词汇表的每个单词时，通过回溯思想 加减 字母表中的数量，来判断是否可以构建出词汇表中的单词

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if (null == words || words.length == 0) return 0;

        int[] table = new int[26];
        for (char c : chars.toCharArray()) {
            table[c - 'a']++;
        }

        int cnt = 0;
        for (String word : words) {
            if (canLearn(word, word.length(), table, 0))
                cnt += word.length();
        }
        return cnt;
    }

    /** backtracking **/
    private boolean canLearn(String word, int wordLen, int[] table, int idx) {
        if (wordLen == idx) return true;

        int charIndex = word.charAt(idx) - 'a';
        if (table[charIndex] <= 0) return false;

        table[charIndex]--;
        boolean ans = canLearn(word, wordLen, table, ++idx);
        table[charIndex]++;
        return ans;
    }
}
```

## 总结
* 方法一是自己写的，优化了几次到了18-19ms左右，后到解题区查看最优方案时发现可以直接用字母加数量来匹配，用了官方提供的也就是方法二，但是发现执行速度太慢了，居然要200左右ms，随后找到了一位大兄弟的思路是提前构建的int[]数组来缓存26个字母及数量以及通过回溯思想来解决used字母，挺不错的，拿了他的代码做了部分优化，可以达到3ms的时间，击败了99.72%。