### 解题思路
理解题意很重要，每个单词对拼写都是一次评写
因此不需要相减

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if (words.length == 0 || chars.length() == 0) {
            return 0;
        }

        //创建数组
        int[] count = new int[26];
        
        //hash计数 chars
        for (int i = 0; i < chars.length(); i++) {
            count[chars.charAt(i) - 'a']++;
        }

        int res = 0;

        a:for (String word : words) {

            int[] countWord = new int[26];
            for (int i = 0; i < word.length(); i++) {
                countWord[word.charAt(i) - 'a']++;
            }

            //判断是否包含数组
            for (int i = 0; i < 26; i++) {
                if (count[i] < countWord[i]) {
                    continue a;
                }
            }

            //包含的话
            res      += word.length();
            
        }

        return res;
    }
}
```