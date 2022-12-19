### 解题思路
简历pattern 与 str对应的映射，并循环是发现不遵守映射关系的单词return false

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        char[] chars = pattern.toCharArray();
        String[] words = str.split(" ");
        if (chars.length != words.length) {
            return false;
        }
        Map<Character, String> patternToWord = new HashMap<>(chars.length);
        for (int i = 0; i < chars.length; i++) {
            if (patternToWord.get(chars[i]) == null) {
                if(patternToWord.containsValue(words[i])){
                    return false;
                }
                patternToWord.put(chars[i], words[i]);
            } else {
                if (!patternToWord.get(chars[i]).equals(words[i])) {
                    return false;
                }
            }
        }
        return true;
    }


}
```