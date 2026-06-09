和leetcode567写法一样 两道题可以一起做
```
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if(s.length() < p.length())
            return res;
        int i = 0;
        int[] hash = new int[26];
        for(int j = 0; j < p.length(); j++)
            hash[p.charAt(j) - 'a']++;
        int match = 0;
        for(int j = 0; j < s.length(); j++)
        {
            hash[s.charAt(j) - 'a']--;
            if(hash[s.charAt(j) - 'a'] >= 0)
                match++;
            while(j - i + 1 > p.length())
            {
                hash[s.charAt(i) - 'a']++;
                if(hash[s.charAt(i) - 'a'] > 0)
                    match--;
                i++;
            }
            if(match == p.length())
                res.add(i);
        }
        return res;
    }
}
```
