```
class Solution {
    public boolean isValid(String s) {
        int a=0;
        int b=0;
        int c=0;
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++){
            
            if(s.charAt(i) == '(' ){
                stack.push(s.charAt(i));
                a=a+1;
            }
            else if(s.charAt(i)== '[' ){
                stack.push(s.charAt(i));
                b=b+1;
            }
            else if(s.charAt(i)== '{' ){
                stack.push(s.charAt(i));
                c=c+1;
            }
            else if(s.charAt(i)== ')'){
                if(  stack.empty()||stack.pop()!='('  ) return false;
                a=a-1;
            }
            else if (s.charAt(i)==']'){
                if(stack.empty()||stack.pop()!='[') return false;
                b=b-1;
            }
            else if(s.charAt(i)=='}')  {
                if(stack.empty()||stack.pop()!='{') return false;
                c=c-1;
            }
        } 
        if(a==0&& b==0 && c==0){
            return true;
        }
        return false;
    }
}
```
