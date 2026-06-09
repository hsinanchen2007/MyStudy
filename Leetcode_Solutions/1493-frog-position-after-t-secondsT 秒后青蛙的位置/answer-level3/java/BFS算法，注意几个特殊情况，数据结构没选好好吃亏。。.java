比赛的时候做完第三题，看第四题就想觉得类似，可惜最后时间不够。。。
注意：
一：虽然是一个无向树，但是给出的数据是用无向图的方式表示，需要用一个便捷的方式存储。。
二：因为是树，所以到目标节点只有一条路径，不然就会有圈
三：注意青蛙到达目标点，如果还有时间有路会跳走，达到概率为0
四：概率计算：除了根节点外，其他都要边数减一再取倒数
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
