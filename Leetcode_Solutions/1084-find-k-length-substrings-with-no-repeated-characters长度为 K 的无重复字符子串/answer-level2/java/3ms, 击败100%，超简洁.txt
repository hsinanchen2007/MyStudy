```
class Solution {
    public int numKLenSubstrNoRepeats(String s, int k) {
        int[] map = new int[26];
        char[] cs = s.toCharArray();
        int l = 0, r = 0, count = 0, res = 0;
        while (r < cs.length) {
            count += map[cs[r++] - 'a']++ == 0 ? 1 : 0;
            res += count == k ? 1 : 0;
            count -= (r >= k && --map[cs[l++] - 'a'] == 0) ? 1 : 0;
        }
        return res;
    }
}
```
