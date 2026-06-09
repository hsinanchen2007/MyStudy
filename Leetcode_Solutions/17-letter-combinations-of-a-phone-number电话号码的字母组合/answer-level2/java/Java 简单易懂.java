感觉就是纯粹的DFS...从前往后遍历，每一步保存当前的字符串，当遍历到最后的时候将所得字符串添加到结果列表中。
```java
class Solution {
    private Map<Character, String> map;
    private List<String> result = new ArrayList<>();
    private String digits;
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0)
            return result;
        
        this.digits = digits;
        map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");

        helper("", 0);
        return result;
    }

    private void helper(String profix, int index) {
        if (index == digits.length()) {
            result.add(profix);
            return;
        }
        String s = map.get(digits.charAt(index));
        for (int i = 0; i < s.length(); i++)
            helper(profix + s.charAt(i), index + 1);
        
    }
}
```
