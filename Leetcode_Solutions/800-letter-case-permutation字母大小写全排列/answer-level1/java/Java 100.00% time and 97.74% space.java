```
class Solution {

    private static final int DIFF = 'A' - 'a';
    public List<String> letterCasePermutation(String S) {
        List<String> res = new ArrayList<>();
        letterCasePermutation(S.toCharArray(), 0, res);
        return res;
    }

    public void letterCasePermutation(char[] chars, int index, List<String> res) {
        if (index == chars.length) {
            res.add(new String(chars));
            return;
        } 
        char c = chars[index];
        if (isLetter(c)) {
            chars[index] = toLower(c);
            letterCasePermutation(chars, index + 1, res);
            chars[index] = toUpper(c);
            letterCasePermutation(chars, index + 1, res);
        } else {
            letterCasePermutation(chars, index + 1, res);
        }
        
    }

    public static boolean isLetter(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public static char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return (char)(c - DIFF);
        }
        return c;
    }

    public static char toUpper(char c) {
        if (c >= 'a' && c <= 'z') {
            return  (char)(c + DIFF);
        }
        return c;
    }

}
```