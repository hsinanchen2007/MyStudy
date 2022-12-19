使用辅助数组存储当前构建的字符串。对输入的数字下标递归，每个数字取一个字母，当递归到最后一个数字时，得到一个可行解。
```
class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Character, List<Character>> dic = new HashMap<>();
        dic.put('2', Arrays.asList(new Character[] {'a', 'b', 'c'}));
        dic.put('3', Arrays.asList(new Character[] {'d', 'e', 'f'}));
        dic.put('4', Arrays.asList(new Character[] {'g', 'h', 'i'}));
        dic.put('5', Arrays.asList(new Character[] {'j', 'k', 'l'}));
        dic.put('6', Arrays.asList(new Character[] {'m', 'n', 'o'}));
        dic.put('7', Arrays.asList(new Character[] {'p', 'q', 'r', 's'}));
        dic.put('8', Arrays.asList(new Character[] {'t', 'u', 'v'}));
        dic.put('9', Arrays.asList(new Character[] {'w', 'x', 'y', 'z'}));
        List<String> result = new ArrayList<>();
        if (digits == null || digits.length() < 1) {
            return result;
        }
        dfs(0, digits, new char[digits.length()], result, dic);
        return result;
    }

    private void dfs(int start, String digits, char[] curr, List<String> result, Map<Character, List<Character>> dic) {
        if (start == digits.length()) {
            result.add(new String(curr));
            return;
        }
        for (Character c : dic.get(digits.charAt(start))) {
            curr[start] = c;
            dfs(start + 1, digits, curr, result, dic);
        }
    }
}
```
