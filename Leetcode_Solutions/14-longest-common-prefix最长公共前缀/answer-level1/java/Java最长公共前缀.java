思路：
找到最小长度字符串，然后依次取该字符串的子串，和其他字符串比较，如果某一个字符串不是以该子串开头，就break，直接比较更短子串。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0){
            return "";
        }
        String s = strs[0];
        for (String str : strs) {
            if (s.length() > str.length()) {
                s = str;
            }
        }
        for (int i = s.length(); i > 0; i--) {
            int count = 0;
            for (String str : strs) {
                if (!str.startsWith(s.substring(0, i))) {
                    break;
                }
                count++;
            }
            if (count == strs.length) {
                return s.substring(0, i);
            }
        }
        return "";
    }
}
```
