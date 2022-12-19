////如果为（则压入栈，如果为 ）则出栈，当栈为空时则找到一个原语（primitive）
class Solution {
public:
    string removeOuterParentheses(string s) {
        
           
         string news1=" ";
         string news2=" ";
         stack<char> tem;
         int n=s.length();
    for(int i=0, j=0;i<n;i++)
    {
    	
    	if('('==s[i])//如果为（则压入栈，如果为 ）则出栈，当栈为空时则找到一个原语（primitive） 
    	  {
    	  	tem.push('(') ;
    	  	
		  }
		  else
		  {
		  	tem.pop();
		  }
		if(tem.empty())
		{
			news1=s.substr(j+1,i-j-1);
			j=i+1;
			news2+=news1;
		}
		
	}
        
        return news2;
    }
};
   
