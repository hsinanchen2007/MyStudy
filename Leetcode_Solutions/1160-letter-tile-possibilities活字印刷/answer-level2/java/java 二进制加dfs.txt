### 解题思路
首先二进制求出来组合，然后进行排列

### 代码

```java
class Solution {

    static Set<String> dict;
	static Set<String> results;
	static int N;
	static boolean[] visited;
	static char[] tes;

    public static int numTilePossibilities(String tiles) {
		String temp=tiles;
		int length=tiles.length();
		dict=new HashSet<String>();
		results=new HashSet<String>();
		char[] dic=temp.toCharArray();
		for(int i=0;i<=(1<<length)-1;i++){
			StringBuffer sb=new StringBuffer();
			int step=0;
			for(int j=0;j<length;j++){
				if((i>>j&1)==1){
					step++;
					sb.append(dic[j]);
				}
			}
			if(step>0){
				dict.add(sb.toString());
			}
			
		}
		for(String str:dict){
			tes=str.toCharArray();
			N=str.length();
			visited=new boolean[N];
			StringBuffer sb=new StringBuffer();
			dfs(0,sb);
		}
		return results.size();
	}
	private static void dfs(int step,StringBuffer sb) {
		if(step==N){
			results.add(sb.toString());
		}
		for(int i=0;i<N;i++){
			if(!visited[i]){
				visited[i]=true;
				int index=step;
				sb.append(tes[i]);
				step++;
				dfs(step,sb);
				visited[i]=false;
				sb.deleteCharAt(index);
				step--;
			}
		}
	}
}
```