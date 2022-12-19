
```
class Solution {
    public String freqAlphabets(String s) {
        //a = 97
        int len = s.length();
        String result = "";
        for (int i = 0; i < len; i++) {
            if (len - i > 2 && s.charAt(i+2) == '#') {
                result += (char)(Integer.parseInt(s.substring(i, i+2)) + 96);
                continue;
            }
            if (len - i > 1 && s.charAt(i+1) == '#' || s.charAt(i) == '#') {
                continue;
            }
            result += (char)(Integer.parseInt(s.substring(i, i+1)) + 96);
        }
        return result;
    }
}
```
