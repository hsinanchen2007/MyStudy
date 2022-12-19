```
class Solution {
    public String removeDuplicateLetters(String s) {
        if(s.length() == 0) return s;
        char[] str = s.toCharArray();
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        StringBuilder sb = new StringBuilder();
        for(char c : str) {
            count[c - 'a']++;
        }

        for(char c : str) {
            count[c - 'a']--;
            // 如果使用，continue
            if(used[c - 'a']) continue;
            while(sb.length() > 0 && sb.charAt(sb.length() - 1) > c && count[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                used[sb.charAt(sb.length() - 1) - 'a'] = false;
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(c);
            used[c - 'a'] = true;
        }
        return sb.toString();
    }
}
```
