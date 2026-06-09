### 解题思路
复制代码，去掉注释，就能知道。用的二维前缀和。

### 代码

```java
class Solution {
	boolean f(int l,int [][]a,int threshold)
	{
		for(int i=l;i<a.length;i++)
		{
			for(int j=l;j<a[0].length;j++)
			{
				int sum=a[i][j]-a[i-l][j]-a[i][j-l]+a[i-l][j-l];
				if(sum<=threshold) return true;
			}
		}
		return false;
	}
    public int maxSideLength(int[][] mat, int threshold) {
        int m=mat.length,n=mat[0].length;
        int [][]a=new int[m+1][n+1];
        for(int i=1;i<m+1;i++)
        {
        	for(int j=1;j<n+1;j++)
        		a[i][j]=a[i-1][j]+a[i][j-1]+mat[i-1][j-1]-a[i-1][j-1];
        }
        /*for(int i=0;i<m+1;i++)
        {
        	for(int j=0;j<n+1;j++)
        		System.out.print(a[i][j]+" ");
        	System.out.println();
        }*/
        for(int i=Math.min(m,n);i>0;i--)
        {
        	if(f(i,a,threshold)) return i;
        }
        
        return 0;
    }
}
```