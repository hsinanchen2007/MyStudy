直接采用递归，当n为最大值时另做处理防止溢出，代码如下

 	public int integerReplacement(int n) 
    {
		if(n==1)
		{
			return 0;//递归出口
		}
		
		int count=0;
	 	
    	if(n%2==0)
    	{
    		count = integerReplacement(n>>1)+1;//n为偶数时直接递归
    	}
    	else 
    	{
    		if(n==Integer.MAX_VALUE)
    		{
    			//n为最大值时作特殊处理,防止溢出
    			count = Math.min(integerReplacement(n-1),integerReplacement(n>>1+1)+1)+1;
    		}else 
    		{
    			//递归,选最小值
    			count = Math.min(integerReplacement(n-1),integerReplacement(n+1))+1;
    		}
    		
    	}
        
        return count;
    }


