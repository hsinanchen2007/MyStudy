### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = -1;
        Map<Character, Integer> map = new HashMap<>();
        int maxLength = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) > start) {
                start = map.get(s.charAt(i));
            }
            map.put(s.charAt(i), i);
            if (i - start > maxLength) {
                maxLength = i - start;
            }
        }
        return maxLength;
    }
}
```