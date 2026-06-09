```
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuffer sb = new StringBuffer();
        Stack stack = new Stack();
        //第一个左括号入库
        for (int i = 0 ;i<S.length();i++){
            if('(' == S.charAt(i)){
                //入栈的时候栈长度大于1
                stack.add(S.charAt(i));
                if(stack.size()>1){
                    sb.append(S.charAt(i));
                }
            }else{
                //出栈的时候栈长度大于1
                stack.pop();
                if(stack.size()>0){
                    sb.append(S.charAt(i));
                }
            }

        }
        return sb.toString();
    }
}
```
