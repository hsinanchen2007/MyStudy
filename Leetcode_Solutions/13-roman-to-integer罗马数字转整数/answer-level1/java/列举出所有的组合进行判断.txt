### 解题思路
    这个题目本来没想写题解，因为我是纯列举的，但是显示我的执行时间超过了88的用户，所以就想把代码粘出来供大家参考比较，没什么解释的，思路没有一点拐弯的地方，就是列举出所有的可能的情况。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
               int ans=0;
        int len=s.length();
        int count=0;
       while(count<=len-1)
        {
    	   
    	  
    	   //是I的时候
    	    if(s.charAt(count)=='I')
           {
    	    	if(count+1==len)
    	    	{
    	    	  ans+=1;
    	    	  count+=1;
    	    	}
        	   //又分为三种情况
    	    	else if(s.charAt(count+1)=='V')
        	   {
        		   ans+=4;
        		   count+=2;
        	   }
        		   else if(s.charAt(count+1)=='X')
        		   {
        			   ans+=9;
        			   count+=2;
        		   }
        		   else 
        		   {
        		   ans+=1;
        		   count+=1;
        		   }
           }
           else  if(s.charAt(count)=='X')
           {
        	   if(count+1==len)
   	    	{
   	    	  ans+=10;
   	    	  count+=1;
   	    	}
        	   //又分为三种情况
        	   else if(s.charAt(count+1)=='L')
        	   {
        		   ans+=40;
        		   count+=2;
        	   }
        		   else if(s.charAt(count+1)=='C')
        		   {
        			   ans+=90;
        			   count+=2;
        		   }
        		   else 
        		   {
        		   ans+=10;
        		   count+=1;
        		   }
           }
           else  if(s.charAt(count)=='C')
           {
        	   if(count+1==len)
   	    	{
   	    	  ans+=100;
   	    	  count+=1;
   	    	}
        	   //又分为三种情况
        	   else if(s.charAt(count+1)=='D')
        	   {
        		   ans+=400;
        		   count+=2;
        	   }
        		   else if(s.charAt(count+1)=='M')
        		   {
        			   ans+=900;
        			   count+=2;
        		   }
        		   else 
        		   {
        		   ans+=100;
        		   count+=1;
        		   }
           }
           else  if(s.charAt(count)=='V')
           {
        	  ans+=5;
        	  count+=1;
        	  
           }
           else  if(s.charAt(count)=='L')
           {
        	  ans+=50;
        	  count+=1;
        	  
           }
           else  if(s.charAt(count)=='D')
           {
        	  ans+=500;
        	  count+=1;
        	  
           }
           else  if(s.charAt(count)=='V')
           {
        	  ans+=5;
        	  count+=1;
        	  
           }
           else  if(s.charAt(count)=='M')
           {
        	  ans+=1000;
        	  count+=1;
        	  
           }
           
        }
        
        return ans;
    }
}
```