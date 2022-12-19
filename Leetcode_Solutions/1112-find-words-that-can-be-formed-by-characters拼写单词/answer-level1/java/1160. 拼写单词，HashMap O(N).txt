### 解题思路
* 先拿一个`HashMap`统计`chars`里的字母出现次数。（`charCount`）
* 然后对于每个`word`，统计他们的字母出现次数，再跟`charCount`里的次数对比。如果`charCount`里单个字母的次数少于`word`里单个字母出现的次数，那么就掌握不了这个单词。

### 代码
```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        // 统计chars里的字母出现次数
        Map<Character, Integer> charCount = new HashMap<Character, Integer>();
        for (int i = 0; i < chars.length(); ++i) {
            char ch = chars.charAt(i);
            Integer count = charCount.get(ch);
            if (count != null) charCount.put(ch, count+1);
            else {
                charCount.put(ch, 1);
            }
        }

        int maxLen = 0;
        Map<Character, Integer> curCharCount = new HashMap<Character, Integer>();
        // 依次判断每个单词是否能被掌握
        for (int i = 0; i < words.length; ++i) {
            curCharCount.clear();
            boolean mastered = true;
            for (int j = 0; j < words[i].length(); ++j) {
                char ch = words[i].charAt(j);
                Integer curCount = curCharCount.get(ch);
                if (curCount == null) curCount = 1;
                else curCount += 1;
                Integer count = charCount.get(ch);
                if (count == null || curCount > count) {
                    mastered = false;
                    break;
                }
                curCharCount.put(ch, curCount);
            }
            if (mastered) {
                maxLen += words[i].length();
            }
        }
        return maxLen;
    }
}
```