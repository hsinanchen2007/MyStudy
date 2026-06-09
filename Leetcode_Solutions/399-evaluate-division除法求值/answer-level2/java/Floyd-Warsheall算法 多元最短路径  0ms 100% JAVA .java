### 解题思路
Floyd的变种。大致为HashMap储存对应表。二维数组储存点之间的权值。再使用Floyd补全。最后需要什么，直接从二维数组里拿就行。
---就先这样，要是有人看。我再写具体。


### 代码

```java
class Solution {
    	 public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
		 final double INF=Integer.MAX_VALUE;
		int len=values.length,max=0;
		HashMap<String, Integer> hash = new HashMap<String, Integer>();
		for (int i=0;i<len;i++){
			String c1=equations.get(i).get(0),c2=equations.get(i).get(1);
			if(!hash.containsKey(c1))
				hash.put(c1, max++);
			if(!hash.containsKey(c2))
				hash.put(c2, max++);
		}
		 double[][] map =new double[max][max];
		 for (int i=0;i<len;i++) {
			 int c1=hash.get(equations.get(i).get(0)),c2=hash.get(equations.get(i).get(1));
			 map[c1][c2]=values[i];
			 map[c2][c1]=1/values[i];
		} 
		 for (int k = 0; k < max; k++) {
			 for (int i = 0; i < max; i++) {
				for (int j = 0; j < max; j++) {
					if(i!=j&&map[i][j]==0&&map[k][j]!=0&&map[i][k]!=0)
						map[i][j]=map[k][j]*map[i][k];
				}
			}
		 }
		 
		 double[] arr=new double[queries.size()];
		 int index=0;
		 for (List<String> ds : queries) {
			if(!hash.containsKey(ds.get(0))||!hash.containsKey(ds.get(1)))
			{
				arr[index++]=-1;continue;
			}
			int c1=hash.get(ds.get(0));
			int c2=hash.get(ds.get(1));
			if(c1==c2)
				arr[index++]=1;
			else if(map[c1][c2]==0)
				arr[index++]=-1;
			else
				arr[index++]=map[c1][c2];
		}
		 
		 return arr;
	 }
}
```