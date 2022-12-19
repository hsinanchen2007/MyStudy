### 代码

```java
class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int wordStart = 0;
        int abbrStart = 0;
        int wordEnd = word.length();
        int abbrEnd = abbr.length();
        while (wordStart < wordEnd && abbrStart < abbrEnd) {
            if (word.charAt(wordStart) == abbr.charAt(abbrStart)) {
                wordStart ++;
                abbrStart ++;
            } else if (abbr.charAt(abbrStart) == '0') {
                return false;
            } else if (abbr.charAt(abbrStart) >= '0' && abbr.charAt(abbrStart) <= '9') {
                int num = 0;
                while (abbrStart < abbrEnd && abbr.charAt(abbrStart) >= '0' && abbr.charAt(abbrStart) <= '9') {
                    num = num * 10 + abbr.charAt(abbrStart) - '0';
                    abbrStart ++;
                }
                wordStart += num; 
            } else {
                return false;
            }
        }
        return wordStart == wordEnd && abbrStart == abbrEnd;
    }
}
```