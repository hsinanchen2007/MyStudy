* 栈空，入栈
* 栈顶为’)'，入栈
* 栈顶为'('，当前为'('，入栈，当前为')'，出栈

```
class Solution {
    public int minAddToMakeValid(String S) {
        Stack<Character> s = new Stack<>();
        for(int i = 0; i < S.length(); i++){
            if(s.isEmpty() || s.peek() == ')') s.push(S.charAt(i));
            else {
                if(S.charAt(i) == '(') s.push(S.charAt(i));
                else s.pop();
            }
        }
        return s.size();
    }
}
```