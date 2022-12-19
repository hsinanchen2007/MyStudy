### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if(s.length()==0)
        return "";
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' ')
            flag=1;
        }
        if(flag==0)
        return "";
        Stack stack=new Stack();
        String number="",count="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '&&i!=s.length()-1)
            number+=s.charAt(i);
            else if(s.charAt(i)==' '&&number!=""){
            stack.push(number);
            number="";
            }
            else if(i==s.length()-1&&s.charAt(i)!=' '){
                number+=s.charAt(i);
                stack.push(number);
            }
        }
        while (!stack.isEmpty()) {
         count+=stack.pop();
         count+=" ";
      }
      StringBuilder sum=new StringBuilder(count);
       sum.delete(sum.length()-1,sum.length());
        return sum.toString();
    }
}
```