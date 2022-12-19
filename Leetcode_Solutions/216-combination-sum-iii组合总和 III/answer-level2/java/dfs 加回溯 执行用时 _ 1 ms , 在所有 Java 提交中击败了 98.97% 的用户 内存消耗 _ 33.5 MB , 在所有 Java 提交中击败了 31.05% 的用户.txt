### 解题思路

### 代码

```java
class Solution {
    static List<List<Integer>> result;
	static int K;
	static int N;
	static ArrayList<Integer> ele;
	static boolean[] visited;

	public static List<List<Integer>> combinationSum3(int k, int n) {
        K=k;
        N=n;
        result=new ArrayList<List<Integer>>();
        visited=new boolean[10];
        ele=new ArrayList<Integer>();
        dfs(1,0,N);
        return result;
    }
	private static void dfs(int n,int step,int num){
		if(step==K&&0==num){
			result.add(new ArrayList<Integer>(ele));
			return;
		}
		if(step>K){
			return;
		}
		for(int i=n;i<=9;i++){
			if(step<K&&!visited[i]){
				visited[i]=true;
				ele.add(i);
				step++;
				dfs(i,step,num-i);
				step--;
				ele.remove(step);
				visited[i]=false;
			}else{
				continue;
			}
		}
	}
}
```