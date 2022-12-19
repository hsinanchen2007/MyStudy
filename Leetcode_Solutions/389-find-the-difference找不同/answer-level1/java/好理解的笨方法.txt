### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     Map<Character, Integer> map = new HashMap<>();

    public char findTheDifference(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        for (int i = 0; i < t.length(); i++) {
            if (!map.containsKey(t.charAt(i))) {
                return t.charAt(i);
            }

            if (map.get(t.charAt(i)) == 1) {
                map.remove(t.charAt(i));
            } else {
                map.put(t.charAt(i), map.get(t.charAt(i)) - 1);
            }
        }
        return ' ';
    }
}
```