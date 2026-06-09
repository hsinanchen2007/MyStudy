执行用时 :
23 ms
, 在所有 Java 提交中击败了
20.58%
的用户
内存消耗 :
37.6 MB
, 在所有 Java 提交中击败了
81.71%
的用户
```
class Solution {
    public int longestValidParentheses(String s) {
       
        int max=0;
      //  char[] ss = s.toCharArray();
        int slen = s.length();
        if(slen<2)return 0;
        byte[] res = new byte[slen];
        Stack<Character> stack = new Stack<Character>();
        Stack<Integer> last = new Stack<Integer>();
         
        for(int i=0; i<slen; i++){
           // char c = (ss[i]);
            char c = s.charAt(i);
            //System.out.println(c);
            if(c==')'){
                if(!stack.isEmpty()&&'('==stack.peek()){
                    stack.pop();
                    res[i]=1;
                    res[last.pop()]=1;
                }
            }else{
                stack.push(c);
                last.push(i);
            }
            
        }
        int count=0;
        for(int i=0; i<slen; i++){
            if(res[i]==1){
                count++;
            }else{
                if(count>max)max=count;
                count=0;
            }
        }
        if(count>max)max=count;
        return max;
    }
}
```
