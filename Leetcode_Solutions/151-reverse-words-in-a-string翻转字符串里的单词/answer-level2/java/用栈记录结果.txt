执行结果：
通过
显示详情
执行用时 :
11 ms
, 在所有 Java 提交中击败了
53.62%
的用户
内存消耗 :
38.5 MB
, 在所有 Java 提交中击败了
91.95%
的用户
```
class Solution {
    public String reverseWords(String s) {
        int len = s.length();
        if(s==null||len==0)return s;
        StringBuffer sb = new StringBuffer();
        Stack<String> stack = new Stack<>();
        for(int i=0; i<len; i++){
            char c = s.charAt(i);
            if(c!=' '){
                sb.append(c);
            }else{
                if(sb.length()>0){
                    stack.push(sb.toString());
                    sb = new StringBuffer();
                }
               
            }
        }
        if(sb.length()>0){
            stack.push(sb.toString());
            sb = new StringBuffer();
        }
         
        while(!stack.isEmpty()){
            sb.append(stack.pop());
            sb.append(" ");
        }
        return sb.length()==0?"":sb.substring(0,sb.length()-1);
    }
}
```
