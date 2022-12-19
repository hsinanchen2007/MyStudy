```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        Map<Character, Integer> charIdx = new HashMap<>();
        int[] m = new int[s.length()];
        int i = 0;
        Integer idx = null;
        for (char c : s.toCharArray()) {
            idx = charIdx.get(c);
            if (idx == null) {
                m[i] = i < 1 ? 1 : m[i - 1] + 1;
            } else {
                if (idx >= i - m[i - 1]) {
                    m[i] = i - idx;
                } else {
                    m[i] = m[i - 1] + 1;
                }
            }
            charIdx.put(c, i);
            i++;
        }
        int max = 0;
        for (int j = 0; j < m.length; j++) {
            if (m[j] > max) {
                max = m[j];
            }
        }
        return max;
    }
}
```
