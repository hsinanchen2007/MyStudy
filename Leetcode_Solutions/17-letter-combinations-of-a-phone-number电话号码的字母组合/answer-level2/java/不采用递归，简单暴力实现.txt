通过临时list赋值直到最终结果
刚开始采用switch catch，时间为1ms，不过比较啰嗦。后改用map后，时间成了2ms。本以为内存占用较多，提交后发现并不算多，30多M，正常水平。

```
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        Map<Character, String> mapper = new HashMap<Character, String>() {{
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }};
        if (digits.equals(""))
            return result;
        else result.add("");
        
        for (int i = 0; i < digits.length(); i++) {
            result = addChar(result, digits.charAt(i), mapper);
        }
        return result;
    }

    public List<String> addChar(List<String> lastResult, char num, Map<Character, String> mapper) {
        List<String> result = new ArrayList<>();
        String s = mapper.get(num);
        for (String last : lastResult) {
            for (int i = 0; i < s.length(); i++) {
                result.add(last + s.charAt(i));
            }
        }
        return result;
    }
}
```

