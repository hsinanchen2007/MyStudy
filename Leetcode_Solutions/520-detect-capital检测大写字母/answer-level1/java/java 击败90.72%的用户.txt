
```
class Solution {
    public boolean detectCapitalUse(String word) {
          char[] chars = word.toCharArray();
        int strLength = word.length();
        int countLow = 0;
        int countUpper = 0;
        for (int i = 0; i < word.length(); i++) {
            if (chars[i] - 'A' >=0 && chars[i] - 'A'<=25){
                countUpper++;
            }else{
                countLow ++;
            }
        }
        if (countLow == strLength ||countUpper == strLength){
            return true;
        }
        if (chars[0] - 'A' >=0 && chars[0] - 'A'<=25 && countLow == strLength-1){
            return true;
        }
        return false;
    }
}
```
