```
class Solution {
    
    private static Map<Character, char[]> map = new HashMap<>(8);
    static {
        map.put('2', new char[] {'a', 'b', 'c'});
        map.put('3', new char[] {'d', 'e', 'f'});
        map.put('4', new char[] {'g', 'h', 'i'});
        map.put('5', new char[] {'j', 'k', 'l'});
        map.put('6', new char[] {'m', 'n', 'o'});
        map.put('7', new char[] {'p', 'q', 'r', 's'});
        map.put('8', new char[] {'t', 'u', 'v'});
        map.put('9', new char[] {'w', 'x', 'y', 'z'});
    }
    
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits == null || "".equals(digits.trim())) {
            return ans;
        }
        backtrack(digits, 0, ans, new StringBuilder());
        return ans;
    }
    
    private void backtrack(String digits, int level, List<String> ans, StringBuilder sb) {
        if (level == digits.length()) {
            ans.add(sb.toString());
            return;
        }
        
        char[] letter = map.get(digits.charAt(level));
        for (int i = 0; i < letter.length; i++) {
            sb.append(letter[i]);
            backtrack(digits, level + 1, ans, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
        
    }
}
```