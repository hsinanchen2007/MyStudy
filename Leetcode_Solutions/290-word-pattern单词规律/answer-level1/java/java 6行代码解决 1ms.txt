单Map, 一遍循环
```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length()) return false;
        Map<Object, Integer> mem = new HashMap<>();
        for (int i = 0; i < words.length; i++) 
            if (!Objects.equals(mem.put(words[i], i), mem.put(pattern.charAt(i), i))) return false;
        return true;
    }
}
```


再放一个可读版本吧, 思路一样

```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern == null && str == null) {
            return true;
        }
        if (pattern == null || str == null) {
            return false;
        }
        String[] word = str.split(" ");
        if (pattern.length() != word.length) {
            return false;
        }
        Map<Object, Integer> mem = new HashMap<>();
        for (int i = 0; i < word.length; i++) {
            Integer pi = mem.put(pattern.charAt(i), i);
            Integer si = mem.put(word[i], i);
            if (!Objects.equals(pi, si)) {
                return false;
            }
        }
        
        return true;
    }
}
```