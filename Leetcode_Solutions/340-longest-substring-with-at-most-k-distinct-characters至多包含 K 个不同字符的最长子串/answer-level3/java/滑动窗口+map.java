```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int max = 0;
        Map<Character, Integer> map = new HashMap();

        for (int i = 0, j = 0; i < s.length() && j < s.length(); ) {
            map.compute(s.charAt(j), (key, v) -> v == null ? 1 : v + 1);

            int num = map.keySet().size();
            if (num <= k) {
                if (j - i + 1 > max) {
                    max = j - i + 1;
                }
                j++;
            } else {
                map.compute(s.charAt(i), (key, v) -> v == null ? 0 : v - 1);
                if (map.get(s.charAt(i)) == 0) {
                    map.remove(s.charAt(i));
                }
                i++;
                j++;
            }
        }

        return max;
    }
}
```