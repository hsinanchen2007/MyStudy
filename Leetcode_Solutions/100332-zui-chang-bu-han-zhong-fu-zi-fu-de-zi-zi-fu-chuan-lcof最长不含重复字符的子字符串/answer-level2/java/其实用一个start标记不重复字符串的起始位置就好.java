
```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int strLen = s.length(), start = 0, res = 0;
        for (int i = 0; i < strLen; ++i) {
            start = Math.max(start, map.getOrDefault(s.charAt(i), -1) + 1);
            map.put(s.charAt(i), i);
            res = Math.max(res, i - start + 1);
        }
        return res;
    }
}
```
