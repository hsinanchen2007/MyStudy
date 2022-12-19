朴素BFS搜素，中间需要注意已经访问过的点不能计算到概率当中，
这个青蛙是死心眼，就算是当前它已经到达target，只要还有其他没有访问过的点，他还是会继续跳，直到时间用完



```
class Solution {
    class  node{
        int id;
        double p;
        int t;
        node(int i,double pp,int tt){
            id=i;
            p=pp;
            t=tt;
        }
    }
    public double frogPosition(int n, int[][] edges, int t, int target) {
        Set<Integer>[] sets=new Set[n+1];
        for(int i=0;i<=n;i++) sets[i]=new HashSet<Integer>();
        for(int[] e:edges){
            sets[e[0]].add(e[1]);
            sets[e[1]].add(e[0]);
        }
        Queue<node> q=new LinkedList<>();
        q.add(new node(1,1.000000,0));
        boolean[] vis=new boolean[n+1];
        vis[1]=true;
        while(!q.isEmpty()){
            node u=q.poll();
            if(u.t==t&&u.id==target){
                return u.p;
            }
            int sz=0;
            for(int nb:sets[u.id]) if(!vis[nb]) sz++;
            if(u.t<t){
                boolean find=false;
                for(int nb:sets[u.id]){
                    if(vis[nb]) continue;
                    find=true;
                    vis[nb]=true;
                    q.add(new node(nb,u.p/sz,u.t+1));
                }
                if(find==false){
                    q.add(new node(u.id,u.p,u.t+1));
                }
            }
            
        }
        return 0.0;

    }
}
```
