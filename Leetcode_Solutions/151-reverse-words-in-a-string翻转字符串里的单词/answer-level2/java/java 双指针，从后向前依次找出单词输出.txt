```
class Solution {
    public String reverseWords(String s) {
        if (s.length() == 0)
            return s;
        String str = s.trim();
        StringBuffer sb = new StringBuffer();
        int i = str.length() - 1, j = str.length();
        while (i > 0) {
            if (str.charAt(i) == ' ') {
                sb.append(str.substring(i + 1, j));
                sb.append(' ');
                while (i > 0 && str.charAt(i) == ' ')
                    i--;
                j = i + 1;
            }
            i--;
        }
        return sb.append(str.substring(0, j)).toString();
    }
}
```
