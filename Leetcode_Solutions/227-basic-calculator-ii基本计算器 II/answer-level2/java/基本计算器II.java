### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int calculate(String s) {
        //基本计算器II：实现四则运算
        Stack<Integer> stack=new Stack<>();
        int sign=1;    //表示正负号
        int msign=0;   //1.表示相乘，  -1.表示相除，  0表示无操作
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(Character.isDigit(ch)){
                //如果它是数字
                int num=ch-'0';
                while(i+1<s.length()&&Character.isDigit(s.charAt(i+1)))
                    num=num*10+s.charAt(++i)-'0';
                if(msign==1)  //相乘
                {
                     stack.push(stack.pop()*num);
                     msign=0;
                }
                else if(msign==-1)  //相除
                {
                     stack.push(stack.pop()/num);
                     msign=0;
                }
                else
                    stack.push(num*sign);
            }
            else if(ch=='+')
                sign=1;
            else if(ch=='-')
                sign=-1;
            else if(ch=='*')
            {
                sign=1;
                msign=1;
            }
            else if(ch=='/'){
                msign=-1;
                sign=1;
            }
        } 
        int res=0;
        while(!stack.isEmpty())
            res+=stack.pop();
        return res;

    }
}
```