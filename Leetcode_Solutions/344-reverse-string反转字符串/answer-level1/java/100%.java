### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public void reverseString(char[] s) 
    {
    	//基本题目：反转字符串
    	//思路：找到中轴线，进行对称反转
    	int midlen = s.length/2;
    	if(s.length%2==0)
    	{
    		for(int i=0;i<midlen;i++)
    		{
	    		char temp=s[midlen+i];
	    		s[midlen+i]=s[midlen-(i+1)];
	    		s[midlen-(i+1)]=temp;
    		}
    		
    	}else
    	{
    		for(int j=1;j<=midlen;j++)
    		{
    			char temp=s[midlen+j];
    			s[midlen+j]=s[midlen-j];
    			s[midlen-j]=temp;    			
    		}
    	}
    }
}
```