### 解题思路
见代码，简单逻辑代码

### 代码

```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            if (words[i].length() != pattern.length())
                continue;

            // 处理对应的逻辑
           if (validPattern(words[i],pattern) && validPattern(pattern,words[i])) {
                res.add(words[i]);
            }

        }
        return res;
    }

    boolean validPattern(String word,String pattern) {
        Map<Character,Character> map = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            if (map.containsKey(ch)) {
                if (map.get(ch) != word.charAt(i))
                    return false;
            }else {
                map.put(ch,word.charAt(i));
            }
        }
        return true;

    }
}
```