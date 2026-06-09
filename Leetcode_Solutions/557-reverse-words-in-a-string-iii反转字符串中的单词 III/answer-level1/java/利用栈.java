### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' ')
            k=1;
        }
        if(k==0)
        return "";
        Stack<Character> stack=new Stack();
        StringBuilder num=new StringBuilder("");
        int flag=0;
        for(int i=0;i<s.length();i++){
            flag=0;
            if(s.charAt(i)!=' ')
           stack.push(s.charAt(i));
           if(s.charAt(i)==' '||i==s.length()-1){
               while(!stack.isEmpty()){
                   num.append(stack.peek());
                   stack.pop(); 
                   flag=1;
               }     
           }
           if(flag==1&&i!=s.length()-1)
           num.append(" ");
        }
        if(num.charAt(num.length()-1)==' '){
           num.delete(num.length()-1,num.length());
        }

        return num.toString();
    }
}
```