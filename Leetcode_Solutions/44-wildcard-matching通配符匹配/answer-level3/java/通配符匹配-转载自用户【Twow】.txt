### 解题思路
注释中已经标出

### 代码

```java
//非本人所编，来自Twow
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] value = new boolean[p.length()+1][s.length()+1];
        value[0][0] = true;                         //这里的【0】【0】表示空与空匹配
        for(int i = 1;i <= s.length();i++){
            value[0][i] = false;                    //p空，s不空，无论如何都不行
        }
        for(int i = 1;i <= p.length(); i++){
            if(p.charAt(i-1) == '*'){  //由于p的charAt从0开始，所以此处的i-1相当于value的i
                value[i][0] = value[i-1][0];        
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = (value[i][j-1] || value[i-1][j]);
                }//如果aaaaa*匹配xxxxxx，那么可以得出aaaaa*一定可以匹配xxxxxxy
                 //如果aaaaa匹配xxxxxxy，那么也可以得出aaaaa*一定可以匹配xxxxxxy
            }else if(p.charAt(i-1) == '?'){
                value[i][0] = false;
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = value[i-1][j-1];
                    //如果aaaa匹配xxxxx，那么可以得出aaaa?匹配xxxxx?
                }
            }else {
                value[i][0] = false;
                for(int j = 1;j <= s.length(); j++){
                    value[i][j] = s.charAt(j-1) == p.charAt(i-1) && value[i-1][j-1];
    //这种情况下，如果aaaa匹配xxxxxx，且新增的a等于新增的x，才能说明aaaaa匹配xxxxxxx
                }
            }

        }
        return value[p.length()][s.length()];

    }
}

//以下为本人所编，然而超时
/**
class Solution {
    public boolean isMatch(String s, String p) {
        
        return snow(s,xiaochu(p));
    }
	public boolean equal(char a,char b)
	{
	    return (b=='?' ? true : a==b);
	}
	          
	    public boolean snow(String s,String p)
	    {
	        for(;p.length()>0;)////&&s.length()>0
	        {
	            if(p.charAt(0)=='*')
	            {
	            	p=p.substring(1);
	                for(int j=0;j<=s.length();j++)
	                {
	                	
	                    if(snow(s.substring(j),p.substring(0))==true)
	                    {
	                        return true;
	                    }
	                    
	                    
	                }
	            }
	            else
	            {
	            	//System.out.println(s+" "+p+" "+"2");
                    if(s.length()==0)
                        return false;
	                if(equal(s.charAt(0),p.charAt(0)))
	                {
	                    s=s.substring(1);
	                    p=p.substring(1);
	                    if(s.length()==0&&p.length()==0)
	                        return true;
	                }
	                else{
	                    return false;
	                }
	            }
	        }
	        //System.out.println(s+" "+p+" "+"1");
	        if(s.length()==0&&p.length()==0)
	        {
	        	
	        	//System.out.println("equal");
	        	return true;
	        }
	        return false;
	    }

    public String xiaochu(String p)
    {
        String q = "";
        char pnow,qnow;
        if(p.length()>0)
        {
            qnow=p.charAt(0);
            q=q.concat(Character.toString(qnow));
            for(int i = 1;i<p.length();i++)
            {
                pnow=p.charAt(i);
                if(pnow=='*'&&qnow=='*')
                {
                }
                else
                {
                    qnow=pnow;
                    q=q.concat(Character.toString(qnow));
                }
            }            
        }
        return q;
    }

}
*/
```