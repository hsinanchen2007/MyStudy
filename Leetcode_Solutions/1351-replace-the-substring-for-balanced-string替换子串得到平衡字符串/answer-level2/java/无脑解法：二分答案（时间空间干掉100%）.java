直接二分答案即可啦
![1.png](https://pic.leetcode-cn.com/a7ad83979b4646e138babc482fc06e943f73a3008965a67053f04cf534830709-1.png)

```
class Solution {
    public int balancedString(String s) {
        int len=s.length();
        int[] a=new int[5];
        for(int i=0;i<s.length();i++)
        	a[change(s.charAt(i))]++;
        if(judge(a,len)) return 0;
        int l=1,r=len,ans=len;
        while(l<=r)
        {
        	int mid=l+(r-l)/2;
        	if(check(s,a,mid))
        	{
        		ans=mid;
        		r=mid-1;
        	}
        	else
        		l=mid+1;
        }
        return ans;
    }
    
    private boolean check(String s,int[] a,int len)
    {
    	int length=s.length();
    	int[] b=new int[5];
    	for(int i=0;i<4;i++) b[i]=a[i];
    	for(int i=0;i<len-1;i++)
    		b[change(s.charAt(i))]--;
    	for(int i=len-1;i<s.length();i++)
    	{
    		b[change(s.charAt(i))]--;
    		int sum=0;
    		boolean flag=true;
    		for(int j=0;j<4;j++)
    		{
    			if(b[j]>length/4) {flag=false;break;}
    			else sum+=length/4-b[j];
    		}
    		if(flag && sum<=len) return true;
    		b[change(s.charAt(i-len+1))]++;
    	}
    	return false;
    }
    
    private int change(char c)
    {
    	if(c=='Q') return 0;
    	if(c=='W') return 1;
    	if(c=='E') return 2;
    	if(c=='R') return 3;
    	return -1;
    }
    
    private boolean judge(int[] a,int len)
    {
        if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3] && a[1]==len/4) 
        	return true;
        return false;
    }
}
```
