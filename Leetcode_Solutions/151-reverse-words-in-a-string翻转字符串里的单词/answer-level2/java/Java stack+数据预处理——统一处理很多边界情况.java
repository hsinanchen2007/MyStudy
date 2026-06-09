这道题各种边界情况实在太多了！！！！！所以我们先讲字符串后加上一个空格……这样的话很多边界情况就不再存在了！会方便很多！
```
class Solution {
    public String reverseWords(String s) {
        String result;
        
        s = s.concat(" ");
        
        int length      = s.length();
        StringBuffer sb = new StringBuffer();
        Stack stack     = new Stack();
        
        for(int i=length-1; i>=0; i--)
        {
            while(s.charAt(i)==' ')
            {
                while(stack.empty()!=true)
                {
                    sb.append(stack.pop());
                }
                if(i==0) break;
                i--;
            }
            
            if(s.charAt(i)!=' ')
            {
                if(i!=length-1 && s.charAt(i+1)==' ')
                {
                    stack.push(' ');
                }
                stack.push(s.charAt(i));
                if(i==0)
                {
                    while(stack.empty()!=true)
                    {sb.append(stack.pop());}
                    break;
                }
            }
        }
        int sblength = sb.length();
        
        if(sblength!=0){result = sb.substring(0,sblength-1);}
        else{result = "";}
        return result;
        

    }
}
```
