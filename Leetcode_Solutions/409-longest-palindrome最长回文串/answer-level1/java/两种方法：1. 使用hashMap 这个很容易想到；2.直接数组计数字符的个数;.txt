```
1. 使用hashMap 这个很容易想到, 时间复杂度为O(n), 空间复杂度O(S), S为字符集大小
class Solution {
    public int longestPalindrome(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }
        Map<Character, Integer> charMap = new HashMap<>();
        for(int i = 0; i< s.length(); i++) {
            charMap.put(s.charAt(i), charMap.getOrDefault(s.charAt(i), 0)+1);
        }
        int res= 0;
        for(Character c:charMap.keySet()) {
            if(charMap.get(c)%2 == 0) {
                res+=charMap.get(c);
            } else {
                res+=(charMap.get(c)-1);
            }
        }

        return res<s.length()?res+1:res;
    }
}
2.直接数组计数字符的个数， 时间复杂度为O(n), 空间复杂度O(S)
class Solution {
    public int longestPalindrome(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }
        int len  = s.length();
        int[] charNums = new int[58];
        for(int i = 0; i < len; i++) {
            charNums[s.charAt(i)-'A']+=1;
        }
        int res= 0;
        for(int c:charNums) {
            res+=(c-(c&1));
        }
        return res<len?res+1:res;
    }
}
```
