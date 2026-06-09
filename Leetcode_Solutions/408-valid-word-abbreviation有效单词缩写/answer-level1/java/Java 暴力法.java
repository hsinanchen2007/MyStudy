双指针 参考@powcai
```
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int j = 0;
        int i = 0;
        while (i < word.length() && j < abbr.length()) {
            if (word.charAt(i) == abbr.charAt(j)) {
                i++;
                j++;
            } else if (abbr.charAt(j) < 65) {
                if (abbr.charAt(j) == '0') {
                    return false;
                }
                String tmp = "";
                while (j < abbr.length() && abbr.charAt(j) < 65) {
                    tmp += abbr.charAt(j);
                    j += 1;  
                }
                i += Integer.parseInt(tmp);
            } else {
                return false;
            }
        }
        return i == word.length() && j == abbr.length();
    }
}
```
