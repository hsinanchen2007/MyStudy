![image.png](https://pic.leetcode-cn.com/6215287df260f83ba4b6c1b13e6ccab385f9412e1bfaf3117067afa71579419c-image.png)
思路：这题和之前打ACM做的题一模一样，一般求解树的直径的问题，最简单高效的方法是先从任意一个点出发进行搜索，直到走到一个最远的点，我们可以证明这个点一定是直径的一个端点，然后再从这个点为起点进行搜索，直到到达从该点出发到达的最远的点，其经过的路径一定是树的直径。
```
import java.util.Vector;
class Solution {
	int ans=0,index=0;
	Vector<Integer>[] q;
    public int treeDiameter(int[][] edges) {
        q=new Vector[edges.length+1];
        for(int i=0;i<=edges.length;i++)
        	q[i]=new Vector();
        for(int i=0;i<edges.length;i++) {
        	q[edges[i][0]].add(edges[i][1]);
        	q[edges[i][1]].add(edges[i][0]);
        }
        dfs(0,-1,0);
        dfs(index,-1,0);
        return ans;
    }				
    
    private void dfs(int u,int p,int sum) {
    	for(int i=0;i<q[u].size();i++) {
    		if(q[u].get(i)==p)
    			continue;
    		dfs(q[u].get(i),u,sum+1);
    	}
    	if(sum>ans) {
    		ans=sum;
    		index=u;
    	}
    }
}

```
