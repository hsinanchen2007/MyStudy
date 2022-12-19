### 解题思路
    新开辟一个数组复制一下数组一，然后按照合并的常规思路向数组一中合并即可。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
         int count=0;
	        int c1=0;
	        int c2=0;
	        int[] nums0=new int[m];
	        for(int i=0;i<m;i++)
	        {
	        	nums0[i]=nums1[i];
	        }
	        while(c1<m&&c2<n)
	        {
	        	if(nums0[c1]<=nums2[c2])
	        	{
	        		nums1[count]=nums0[c1];
	                count++;
	                c1++;
	        	}
	        	else
	        	{
	        		nums1[count]=nums2[c2];
	        	    count++;
	        	    c2++;
	        	}
	        }
	        if(c1<m)
	        {
	        	while(c1<m)
	        	{
	        		nums1[count]=nums0[c1];
	        		c1++;
	        		if(count<(m+n))
	        			count++;
	        	}
	        }
	        else 
	        {
	        	while(c2<n)
	        	{
	        		nums1[count]=nums2[c2];
	        		c2++;
	        		if(count<(m+n))
	        			count++;
	        	}
	        }
	        
    }
}
```