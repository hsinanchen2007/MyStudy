### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int calculate(String s) {
        int sign=1;  //sign表示加减符号
        int msign=0; //msign表示乘除符号，1表示乘法，-1表示除法，0表示不操作
        int num=0;
        int len=s.length();
        Stack <Integer> stack=new Stack<>();
        for(int i=0;i<len;i++){
            char ch=s.charAt(i);
            if(Character.isDigit(ch)){
                num=ch-'0';
                while(i+1<len&&Character.isDigit(s.charAt(i+1)))    
                    num=num*10+s.charAt(++i)-'0';
                if(msign==1)       //乘法
                {
                    stack.push(stack.pop()*num);
                    msign=0;
                }
                else if(msign==-1)  //除法 
                {
                    stack.push(stack.pop()/num);
                    msign=0;
                }
                else                 //加减
                    stack.push(sign*num);
            }
            else if(ch=='+')
                sign=1;
            else if(ch=='-')
                sign=-1;
            else if(ch=='*')
            {
                msign=1;  
            }
            else if(ch=='/')
                msign=-1;
        }
        int res=0;
        while(!stack.isEmpty())
            res+=stack.pop();
        return res;
    }
}
```