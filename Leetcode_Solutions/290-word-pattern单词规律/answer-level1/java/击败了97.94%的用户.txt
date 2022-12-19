### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] splits = str.split(" ");
        if (pattern.length() != splits.length) {
            return false;
        } 
        Map<Character, String> mapping = new HashMap<>();
        Map<String, Character> reverse = new HashMap<>();
        for (int i = 0; i < splits.length; ++i) {
            String s = mapping.get(pattern.charAt(i));
            Character c = reverse.get(splits[i]);
            if (s == null && c == null) {
                mapping.put(pattern.charAt(i), splits[i]);
                reverse.put(splits[i], pattern.charAt(i));
            } else if (s != null && c != null) {
                if ((!s.equals(splits[i]) || !c.equals(pattern.charAt(i)))) {
                    return false;
                }
            } else {
                return false;
            }
            
        }
        return true;

    }
}
```