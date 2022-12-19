### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if (pattern == null || str == null) {
            return false;
        }
        String[] split = str.split(" ");
        if (pattern.length() != split.length) {
            return false;
        }
        Map<Character, String> m = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            if (m.get(pattern.charAt(i)) == null) {
                if (m.containsValue(split[i])) {
                    return false;
                }
                m.put(pattern.charAt(i), split[i]);
            } else {
                if (!m.get(pattern.charAt(i)).equals(split[i])) {
                    return false;
                }
            }
        }
        return true;
    }
}
```