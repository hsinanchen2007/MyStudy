class Solution {
    String[] map = new String[] {
            "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) return res;
        StringBuilder path = new StringBuilder();
        help(0, digits, path, res);
        return res;

    }

    private void help (int index, String digits, StringBuilder path, List<String> res) {
        if (index == digits.length()) {
            res.add(path.toString());
            return;
        }
        char ch = digits.charAt(index);
        String str = map[ch - '1'];
        for (int i = 0; i < str.length(); i++) {
            char tmp = str.charAt(i);
            help(index + 1, digits, path.append(tmp), res);
            path.deleteCharAt(path.length() - 1);
        }

    }
}