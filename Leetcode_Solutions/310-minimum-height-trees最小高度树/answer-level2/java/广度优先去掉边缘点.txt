```java []
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(n==1) {
            List<Integer> res=new ArrayList();
            res.add(0);
            return res;
        }
        ArrayList<ArrayList<Integer>> adjacent_list=new ArrayList();
        for(int i=0;i<n;i++)
            adjacent_list.add(new ArrayList());
        int[] degree=new int[n];
        int v1,v2;
        // 构建邻接表
        for(int[] edge:edges){
            v1=edge[0];v2=edge[1];
            degree[v1]++;degree[v2]++;
            adjacent_list.get(v1).add(v2);
            adjacent_list.get(v2).add(v1);
        }

        Deque<Integer> Q=new LinkedList();
        List<Integer> res=new ArrayList();
        ////逐层去掉度为1的边缘结点
        for(int i=0;i<n;i++){
            if(degree[i]==1) Q.add(i);
        }
        int cur,size;
        ArrayList<Integer> next_vex = new ArrayList();
        while(Q.isEmpty()==false){
            res.clear();
            size=Q.size();
            for(int i=0;i<size;i++){
                cur=Q.poll();
                res.add(cur);
                next_vex=adjacent_list.get(cur);
                for(Integer vex:next_vex){
                    degree[vex]-=1;
                    if(degree[vex]==1) Q.add(vex);
                }
            }
        }
        return res;
    }
}
```

