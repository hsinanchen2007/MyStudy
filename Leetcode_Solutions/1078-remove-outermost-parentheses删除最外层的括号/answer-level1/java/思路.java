使用一个栈来消去最外层的括号
使用一个信号量来表示内层是否完整
```
    class Solution {
    public static String removeOuterParentheses (String s){
        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<Character>();
        Queue<Character> queue = new LinkedList<Character>();
        int completed = 0;
        for(int i = 0;i<s.length();i++){
            if(stack.empty() && s.charAt(i) == '('){
                stack.push(s.charAt(i));
            }
            else if(!stack.empty()){
                if(completed == 0 && s.charAt(i) == ')'){
                    stack.pop();
                }
                else if(s.charAt(i)=='('){
                    queue.add(s.charAt(i));
                    completed -= 1;
                }
                else if(s.charAt(i)==')'&&completed!=0){
                    queue.add(s.charAt(i));
                    completed += 1;
                }else{
                    queue.add(s.charAt(i));
                }
            }
        }
        
        while(queue.size()!=0){
            sb.append(queue.remove());
        }
        return sb.toString();

    }
}
```