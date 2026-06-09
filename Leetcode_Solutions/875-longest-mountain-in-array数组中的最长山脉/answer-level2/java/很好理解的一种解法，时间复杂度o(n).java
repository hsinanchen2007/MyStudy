思路：
1.遍历每个点左边的坡有多高

2.遍历每个点右边的坡有多高

3. 左右加起来比最大值
if(A.length==0)
		{
			return 0;
		}
        int left[] = new int[A.length];
        int right[] = new int[A.length];
        int max = 0;
        for(int i=1;i<A.length;i++)
        {
        	if(A[i]>A[i-1])
        	{
        		left[i]=left[i-1]+1;
        		if(left[i-1]==0)  //如果i-1处是0，现在left[i]就要变成2，而不是1，所以再加个1
        		{
        			left[i]++;
        		}
        	}
        	else
        	{
        		left[i]=0;
        	}
        }
        for(int i=A.length-2;i>=0;i--)
        {
        	if(A[i+1]<A[i])
        	{
        		right[i]=right[i+1]+1;
        		if(right[i+1]==0)
        		{
        			right[i]++;
        		}
        	}
        	else
        	{
        		right[i]=0;
        	}
        }
        for(int i=0;i<A.length;i++)
        {
        	if(left[i]!=0&&right[i]!=0)
        	{
        		max = Math.max(max, left[i]+right[i]);
        	}
        	
        }
        if(max==0)
        {
        	return 0;
        }
        return max-1;//山峰左右都算了它的高度，所以最后要减一