
回溯算法实现：
```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        if (n == 0)
            return list;
        backtrack("", 0, 0, n, list);
        
        return list;
    }
    
    // open:左括号的个数；close:右括号的个数;n:括号对数
    private void backtrack(String combination, int open, int close, int n, List<String> list) {
        if (combination.length() == 2 * n) {
            list.add(combination);
            return;
        }
        //如果左括号小于n，即还可以添加左括号
        if (open < n) {
            backtrack(combination + "(", open + 1, close, n, list);
        }
        //如果右括号小于左括号(必须如此，这样的括号才是有效的)
        if (close < open) {
            backtrack(combination + ")", open, close + 1, n, list);
        }
    }
}
```
