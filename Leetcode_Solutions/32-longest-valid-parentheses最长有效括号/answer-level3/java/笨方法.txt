看到括号配对的就想到栈 写了个笨方法分享下
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Character> ss= new Stack<Character>();
        char[] dd= s.toCharArray();
        Stack<Integer> rem = new Stack<>();
       ArrayList<Integer> va = new ArrayList<Integer>();
         int len = dd.length;
        int number=0;
        int max=0;
        for(int i=0 ; i<len ; i++)
        {
            if(dd[i]=='('){ 
                ss.push('('); 
                rem.push(number);
                          }
            if(dd[i]==')'){
             if(!ss.empty()) {  if(ss.peek()=='(') { number+=2;ss.pop();rem.pop();}}
                else {va.add(number);number = 0;}
            }
        }
    
        if(number > 0){
            if(rem.empty()) max=number;
                    while(!rem.empty())
                    {
                        if(rem.peek()<number) {va.add(number-rem.peek());number=rem.peek(); }
                          rem.pop();
                    }
                 va.add(number);
          
                }
        
        
            for(int i=0 ;i<va.size();i++){
                if(max<=va.get(i)) max=va.get(i);
                
            }
            return max;
        
    }
}