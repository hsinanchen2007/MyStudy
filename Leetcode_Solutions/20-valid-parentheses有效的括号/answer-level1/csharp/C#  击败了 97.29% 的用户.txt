```
public class Solution {
    public bool IsValid(string s) {
        if(s.Length==0)return true;
        if(s.Length%2==1)return false;
        if(s[0]==')'||s[0]=='}'||s[0]==']') return false;
        Stack<char> stack=new Stack<char>();
        foreach(var i in s){
            if(i=='('||i=='{'||i=='['){
                    stack.Push(i);
            }
            else if(i==')'){
                if(stack.Peek()=='('){
                    stack.Pop();
                }else{
                    stack.Push(i);
                }
            }
            else if(i==']'){
                if(stack.Peek()=='['){
                    stack.Pop();
                }else{
                    stack.Push(i);
                }
            }
            else if(i=='}'){
                if(stack.Peek()=='{'){
                    stack.Pop();
                }else{
                    stack.Push(i);
                }
            }
        }
        return stack.Count==0;
    }
}
```