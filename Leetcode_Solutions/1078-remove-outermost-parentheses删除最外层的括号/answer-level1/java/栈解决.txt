```
class Solution {
    public String removeOuterParentheses(String S) {
        Stack<Character> leftStack = new Stack<>();
        StringBuilder res = new StringBuilder();
        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) == '('){
                if(leftStack.size() > 0){
                    res.append('(');
                }
                leftStack.add('(');
            }
            else{
                if(leftStack.size() == 1){
                    leftStack.pop();
                }
                else{
                    leftStack.pop();
                    res.append(')');
                }
            }
        }
        return res.toString();
    }
}
```
