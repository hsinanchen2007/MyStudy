### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int res = 0;
        for (String word : words) {
            int[] cns = new int[26];
            for (int i = 0; i < chars.length(); i++) {
                cns[chars.charAt(i) - 'a']++;
            }

            int i;
            for (i = 0; i < word.length(); i++) {
                cns[word.charAt(i) - 'a']--;
                if(cns[word.charAt(i) - 'a'] < 0) {
                    break;
                }
            }
            if(i == word.length()) {
                res += word.length();
            }
        }

        return res;
    }
}
```