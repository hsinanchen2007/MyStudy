### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    static int E;
	static boolean[] visited;
	static int result;

    	public static int countArrangement(int N) {
		result=0;
        E=N;
		visited=new boolean[E+1];
		int step=1;
		dfs(step);
		return result;
    }
	private static void dfs(int step) {
		if(step==E){
			result++;
		}
		for(int i=1;i<=E;i++){
			if(!visited[i]){
				visited[i]=true;
				step++;
				if(i%step==0||step%i==0){
					dfs(step);
				}
				step--;
				visited[i]=false;
			}
		}
	}
}
```