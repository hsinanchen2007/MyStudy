```
class Solution {
    List<List<Integer>> graph=new LinkedList<>();
    int[] father;
    int res=0;
    public int treeDiameter(int[][] edges) {
        int n=edges.length+1;
        father=new int[n];
        for (int i = 0; i < n; i++) {
            graph.add(new LinkedList<>());
        }
        //建立图（点与点相互之间的关系）
        for (int i = 0; i < edges.length; i++) {
            int p=edges[i][0];
            int q=edges[i][1];
            graph.get(p).add(q);
            graph.get(q).add(p);
        }
        dfs(0,-1);
        solve(0,-1);
        return res;
    }

    //建立父子关系 f=father c=childern tempc=tempchildren
    private void dfs(int c,int f){
        father[c]=f;
        for(int tempc:graph.get(c)){
            if(tempc==f) continue;
            dfs(tempc,c);
        }
    }

    //确定res
    private int solve(int c,int f){
        List<Integer> lens=new LinkedList<>();
        for(int tempc:graph.get(c)){
            if(tempc==f) continue;
            lens.add(solve(tempc,c));
        }
        Collections.sort(lens);
        if(lens.size()==0) {//叶子节点直接返回1
            return 1;
        }else if(lens.size()==1){//只有一个孩子
            res= Math.max(res,lens.get(0));
            return lens.get(0)+1;
        }else{
            res=Math.max(res,lens.get(lens.size()-1)+lens.get(lens.size()-2));
            return lens.get(lens.size()-1)+1;
        }
    }
}
[@daodao-2](/u/daodao-2/)
[https://www.bilibili.com/video/av74372530]
```
