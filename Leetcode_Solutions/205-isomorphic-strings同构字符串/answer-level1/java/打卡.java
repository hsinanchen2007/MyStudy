### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Character> charMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Character sc = s.charAt(i);
            Character tc = t.charAt(i);
            if (charMap.containsKey(sc)) {
                if (!charMap.get(sc).equals(tc)) {
                    return false;
                }
            } else {
                charMap.put(sc, tc);
            }
        }
        if (charMap.values().stream().distinct().collect(Collectors.toList()).size() != charMap.size()) {
            return false;
        }
        return true;
    }
}
```