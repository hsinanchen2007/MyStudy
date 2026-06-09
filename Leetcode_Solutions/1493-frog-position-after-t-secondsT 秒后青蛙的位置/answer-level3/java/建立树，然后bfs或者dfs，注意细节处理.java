bfs:注意到达目标点后还有时间和节点会让概率置0
dfs:注意选择下一步时减去相应的概率，就会让跳过的点概率归0
```
class Solution {

    int[] visited=new int[105];  
    double[] res=new double[105];
	HashMap<Integer,List<Integer>> map=new HashMap<>();
	public double frogPosition(int n, int[][] edges, int t, int target) {

		for(int i=0; i<edges.length; i++) {
			if(map.containsKey(edges[i][0])) {
				map.get(edges[i][0]).add(edges[i][1]);
			} else {
				List<Integer> ls=new ArrayList<>();
				ls.add(edges[i][1]);
				map.put(edges[i][0],ls);
			}
            if(map.containsKey(edges[i][1])) {
				map.get(edges[i][1]).add(edges[i][0]);
			} else {
				List<Integer> ls=new ArrayList<>();
				ls.add(edges[i][0]);
				map.put(edges[i][1],ls);
			}
		}
        visited[1]=1;
        res[1]=1.0;
        dfs(1,t);
		return res[target];
	}
    public void dfs(int i,int t){
        if(t==0) return;
        List<Integer> ls=map.get(i);
        if(ls==null) return;
        double p=i==1?res[i]/ls.size():res[i]/(ls.size()-1);
        for(int next:ls){
            if(visited[next]!=1){
                visited[next]=1;
                res[i]-=p;
                res[next]+=p;
                dfs(next,t-1);
                visited[next]=0;
            }
        }

    }
}

```

```
class Solution {
	HashMap<Integer,List<Integer>> map=new HashMap<>();
	public double frogPosition(int n, int[][] edges, int t, int target) {
		for(int i=0; i<edges.length; i++) {
			if(map.containsKey(edges[i][0])) {
				map.get(edges[i][0]).add(edges[i][1]);
			} else {
				List<Integer> ls=new ArrayList<>();
				ls.add(edges[i][1]);
				map.put(edges[i][0],ls);
			}
            if(map.containsKey(edges[i][1])) {
				map.get(edges[i][1]).add(edges[i][0]);
			} else {
				List<Integer> ls=new ArrayList<>();
				ls.add(edges[i][0]);
				map.put(edges[i][1],ls);
			}
		}
        int[] flag=new int[n+1];
        
		Queue<Integer> queue=new LinkedList<>();
		double[] res=new double[n+1];
		res[1]=1.0;
        flag[1]=1;
		queue.offer(1);
		while(!queue.isEmpty()) {
			if(res[target]!=0||t==0) {
				break;
			}
			int num=queue.size();
			for(int i=0; i<num; i++) {
				int cur=queue.poll();
				List<Integer> ls=map.get(cur);
				if(ls!=null) {
                    for(int x:ls) {
                        if(flag[x]==0){
                            if(cur!=1){
                                res[x]=res[cur]*1.0/(double)(ls.size()-1);
                            }else{
                                res[x]=res[cur]*1.0/(double)(ls.size());
                            }
                            flag[x]=1;
                            queue.offer(x);
                        }
					}
				}
			}
			t--;
		}
        if(t>0){
            List<Integer> ls=map.get(target);
            if(ls!=null){
                for(int m:ls){
                    if(flag[m]==0){
                        return 0.0;
                    }
                }
            }
        }
		return res[target];
	}
}

```

