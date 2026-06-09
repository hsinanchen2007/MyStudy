### 解题思路
参考各位大佬的想法写的，就是要记得上一个访问的边的颜色，还要记录访问过的点。写起来没什么，就是可能容易乱。

### 代码

```java
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
    	Queue<int []>queue=new LinkedList();
        int []res=new int[n];
        int [][]p=new int[n][n];
        int [][][]visited=new int[n][n][2];
        for(int i=0;i<red_edges.length;i++)
        {
        	int l=red_edges[i][0],r=red_edges[i][1];
        	p[l][r]+=1;
        }
        for(int i=0;i<blue_edges.length;i++)
        {
        	int l=blue_edges[i][0],r=blue_edges[i][1];
        	p[l][r]+=2;
        }
        int []b= {0,0,0};//0,0,red
        queue.add(b.clone());
        b=new int[]{0,0,1};
        queue.add(b.clone());
        while(queue.size()>0)
        {
        	b=queue.poll().clone();
           // System.out.println(b[0]+" "+b[1]+" "+b[2]);
        	if(res[b[0]]==0)
        		res[b[0]]=b[1];
        	//else res[b[0]]=Math.min(res, b)
        	if(b[2]==0)
        	{
        		int start=b[0];
        		for(int i=0;i<n;i++)
        		{
        			if(p[start][i]>1&&visited[start][i][b[2]]==0)
        			{
        				int []end= {i,b[1]+1,1};
        				visited[start][i][b[2]]=1;
        				queue.add(end);
        			}
        			
        		}
        	}
        	if(b[2]==1) 
        	{
        		int start=b[0];
        		for(int i=0;i<n;i++)
        		{
        			if((p[start][i]==1||p[start][i]==3)&&visited[start][i][b[2]]==0)
        			{
        				int []end= {i,b[1]+1,0};
        				visited[start][i][b[2]]=1;
        				queue.add(end);
        			}
        			
        		}
        	}
        }
        for(int i=1;i<res.length;i++)
        if(res[i]==0) res[i]=-1;
        res[0]=0;
        return res;
    }
}
```