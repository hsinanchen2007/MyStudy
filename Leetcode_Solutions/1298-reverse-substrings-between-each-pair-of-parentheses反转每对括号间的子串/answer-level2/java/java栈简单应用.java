



栈的简单应用。把左括号的序号依次压入栈，当匹配到最近的右括号，就pop出来，并反转中间的字符串



```



class Solution {
    public String reverseParentheses(String s) {
    	StringBuilder str=new StringBuilder();
        Stack <Integer>stack=new Stack<>();
    	char[] first=s.toCharArray();
    	for(int i=0;i<s.length();i++)
    	{
    		if(first[i]=='(')
    		stack.push(i);
    		
    		if(first[i]==')')
    		{
    			reverse(first,stack.pop()+1,i-1);
    		}
    		
    			
    		
    		
    		
    		
    		
    	}
    	
    	for(int i=0;i<first.length;i++)
    	{
    		if((first[i]!='(')&&(first[i]!=')'))
    		  str.append(first[i]);
    	}
    	
    	
    	
    	
    	
    	return str.toString();
    }
    
    
    
    public void reverse(char[] a,int i,int j) {
    	
    	while(i<j)
    	{
    		char o=a[i];
    		a[i]=a[j];
    		a[j]=o;
    		i++;
    		j--;
    		
    		
    		
    	}
    	
    	
    	
    	
    	
    }
}```