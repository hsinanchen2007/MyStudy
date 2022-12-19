### 解题思路
我的想法就是去掉所有的括号，要知道运算法则里怎么说来着，要先算括号里的。这就是我的想法。
唯一的难点可能就是 (1+5-3)-(3+6-5-4-3)这种情况，我巧妙的避开了  3--3 
但是效率不高。因为一直在替换。
### 代码

```java
class Solution {
	int f(String s)
	{
		s=s.replaceAll("\\+\\+", "+");
		s=s.replaceAll("\\+\\-", "-");
		s=s.replaceAll("\\-\\+", "-");
		s=s.replaceAll("\\-\\-", "+");
		int res=0,m=0,flag=0;
        //System.out.println(s);
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i)!='+'&&s.charAt(i)!='-')
			{
				m=m*10+s.charAt(i)-'0';
			}
			else 
			{
				if(flag==0)
					res+=m;
				else res-=m;
				m=0;
				if(s.charAt(i)=='+') flag=0;
				else flag=1;
			}
		}
		if(flag==0)
			res+=m;
		else res-=m;
		return res;
	}
    public int calculate(String s) {
        s=s.replaceAll(" ","");
        StringBuffer s1=new StringBuffer(s);
        while(s1.indexOf("(")!=-1)
        {
        	boolean flag=true;
        	int former=0,latter=0;
        	for(int i=0;i<s1.length();i++)
        	{
                //System.out.println(s1);
        		if(s1.charAt(i)=='(')
        		{
        			former=i;
        			for(int j=i+1;j<s1.length();j++)
        			{
        				if(s1.charAt(j)==')')
        				{
        					latter=j;
        					String sum=s1.substring(former+1,latter);
        					int res=f(sum);
        					s1=s1.replace(former, latter+1,""+res);
        					flag=false;
        					break;
        				}
        				else if(s1.charAt(j)=='(')
        				{
        					former=j;
        				}
        			}
        		}
        		if(!flag) break; 
        	}
        }
        //System.out.println(s1);
        return f(s1.toString());
    }
}
```