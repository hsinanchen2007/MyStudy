### 解题思路
写的稍微有点啰嗦，但是保证了准确性。
### 代码

```java
class Solution {
	int []a;
	int find(int x)
	{
		if(x!=a[x])
		a[x]=find(a[x]);
	    return a[x];
	}
	class MyCom implements Comparator<int []>
	{
		public int compare(int[] o1, int[] o2) {
			return Integer.compare(o1[0],o2[0]);
		}
		
	}
	boolean is(int []a)
	{
		for(int i=1;i<a.length;i++)
		{
			if(a[i]!=a[0]) return false;
		}
		return true;
	}
    public int earliestAcq(int[][] logs, int N) {
    Arrays.sort(logs,new MyCom());
    a=new int[N];
    for(int i=0;i<a.length;i++) a[i]=i;
    for(int i=0;i<logs.length;i++)
    {
    	int time=logs[i][0],id1=logs[i][1],id2=logs[i][2];
    	int f1=a[id1],f2=a[id2];
    	if(f1>f2) 
    	{
    		f1^=f2;
    		f2^=f1;
    		f1^=f2;
    	}
    	int m=find(f1);
    	a[id1]=m;a[id2]=m;
    	for(int j=0;j<N;j++)
    	{
    		if(a[j]==f2||a[j]==f1) a[j]=m;
    	}
    	if(is(a)) return time;
    }
    return -1;
    }
}
```