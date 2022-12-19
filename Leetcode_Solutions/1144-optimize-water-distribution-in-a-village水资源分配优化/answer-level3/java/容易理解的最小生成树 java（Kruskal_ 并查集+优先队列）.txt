```
class Solution {
    private class UnionFind{
        int[] parent;
        int[] rank;
        public UnionFind(int n){
            parent = new int[n];
            rank = new int[n];
            for(int i = 0; i< n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x){
            return parent[x] == x?x:(parent[x] = find(parent[x]));
        }
        void union(int x, int y){
            int first = find(x);
            int second = find(y);
            if(first == second){
                return;
            }
            if(rank[first]>rank[second]){
                parent[second] = first;
            }else if(rank[first]<rank[second]){
                parent[first] = second;
            }else{
                parent[first] = parent[second];
                rank[second]++;
            }
        }
        boolean isConnect(int x, int y){
            return find(x) == find(y);
        }
    }
    
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        PriorityQueue<int[]> queue = new PriorityQueue<>((a,b)->a[2]-b[2]);
        for(int[] pip: pipes){
            queue.offer(pip);
        }
        //加入虚拟节点0(如果两处都挖井，则不需要管道相连)
        for(int i =0; i< wells.length; i++){
            int[] temp = new int[3];
            temp[0] = 0;
            temp[1] = i+1;
            temp[2] = wells[i];
            queue.offer(temp);
        }
        UnionFind union = new UnionFind(n+1);
        int res =0;
        while(!queue.isEmpty()){
            int[] cost = queue.poll();
            if(union.isConnect(cost[0], cost[1])){
                continue;
            }
            union.union(cost[0], cost[1]);
            res+= cost[2];
        }
        return res;
    }
}
```
