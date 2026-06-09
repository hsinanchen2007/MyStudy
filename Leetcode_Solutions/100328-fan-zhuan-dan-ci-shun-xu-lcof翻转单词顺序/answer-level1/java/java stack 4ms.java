分割出每个单词并压入stack中，再使用StringBuilder连接成字符串
```
class Solution {
    public String reverseWords(String s) {
        Stack<String> stack=new Stack<>();
        int len=s.length();
        if(len==0)return s;
        int left=0,right=0;
        while(left<len){
            while(left<len&&s.charAt(left)==' ')left++;
            right=left+1;
            while(right<len&&s.charAt(right)!=' ')right++;
            if(left<len)stack.push(s.substring(left,right));    
            left=right;
        }
        StringBuilder res=new StringBuilder();
        while(!stack.isEmpty()){
            res.append(stack.pop());
            if(stack.size()>0)res.append(" ");
        }
        return res.toString();
    }
}
```
