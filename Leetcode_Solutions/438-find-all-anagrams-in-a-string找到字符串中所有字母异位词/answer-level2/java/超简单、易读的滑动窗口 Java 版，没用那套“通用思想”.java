```
class Solution {
    public List<Integer> findAnagrams(String s, String p)  {
        List<Integer> res = new ArrayList<>();
        if (s == null || s.length() == 0 || p == null || p.length() == 0 || s.length() < p.length())
            return res;
        int [] inP = new int[26];
        for (char c: p.toCharArray()) 
            inP[c - 'a'] ++;
        int[] window = new int[26];
        for (int i = 0; i < p.length(); i ++) 
            window[s.charAt(i) - 'a'] ++;
        if (Arrays.equals(window, inP)) 
            res.add(0);

        for (int l = 0, r = p.length(); r < s.length(); l ++, r ++) {
            window[s.charAt(l) - 'a'] --;
            window[s.charAt(r) - 'a'] ++;
            if (Arrays.equals(window, inP)) {
                res.add(l + 1);
            }
        }
        return res;
    }
}
```
