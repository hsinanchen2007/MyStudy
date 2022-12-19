这里有个建议，虽然粗俗易懂的解法容易明白解答出这道题，但是不要仅仅停留在解答出这道题的层面上，解答出来每道题，一定要多看看大佬们的多种解法，学习更多的解题方法和思路，用来学习加深和扩展自己的解决问题的思维能力
```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        int LC = 0, RC = 0;
        method(1, 0, result, "(", n); // 第一个必定是左括号
        return result;
    }

    /**
     * 回溯
     * @param LC 当前拼接的字符串中左括号的数量
     * @param RC 当前拼接的字符串中右括号的数量
     * @param result
     * @param preString
     * @param n
     */
    public void method(int LC, int RC, List<String> result, String preString, int n) {
        if(LC == n && RC == n) { // 如果左括号和右括号数量相等，说明已经是最终拼接
            result.add(preString);
            return;
        }
        if(LC < n) { // 左括号数量还有，则就添加左括号
            method(LC + 1, RC, result, preString + "(", n);
        }

        if(RC < n && LC > RC) { // 右括号还有，并且字符串中左括号的数量要大于右括号的数量，否则就会出现问题
            method(LC, RC + 1, result, preString + ")", n);
        }
    }
}
```
