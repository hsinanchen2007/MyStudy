* 栈空 或 当前元素不等于栈顶元素，入栈
* 否则就是栈不为空 且 当前元素等于栈顶元素，栈顶元素出栈
* 遍历完S后栈中剩下的就是结果字符串

```
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> s = new Stack<>();
        for(int i = 0; i < S.length(); i++){
            if(s.isEmpty() || s.peek() != S.charAt(i))
                s.push(S.charAt(i));
            else s.pop();
        }
        char[] res = new char[s.size()];
        for(int i = s.size() - 1; i >= 0; i--)
            res[i] = s.pop();
        return String.valueOf(res);
    }
}
```