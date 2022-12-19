```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        // 字母表数组
        int[] table = new int[26];
        for (int i = 0; i < chars.length(); i++)
            table[chars.charAt(i) - 'a']++;
        // 单词长度
        int count = 0;
        for (String str : words) {
            if (canSpellWords(str, table))
                count += str.length();
        }
        return count;
    }
    
    public boolean canSpellWords(String str, int[] table) {
        int[] tmp = new int[26];
        for (int i = 0; i < str.length(); i++) {
            char now = str.charAt(i);
            // 临时表 和 字母表值相等，代表字母不存在 
            if (tmp[now - 'a'] == table[now - 'a'])
                return false;
            tmp[now - 'a']++;
        }
        return true;
    }
}
```
