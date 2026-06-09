学习了大佬的并查集博客之后，终于知道并查集是什么了 https://blog.csdn.net/niushuai666/article/details/6662911
```
class Solution {
    int[] pre;
    public int[] findRedundantConnection(int[][] edges) {
        //N个节点，M 个关系
        int N = edges.length; //N表示有多少个节点
        pre = new int[1001];
        int[] target = new int[2];

        //初始化
        for(int i=1; i<=N; i++)
            pre[i] = i;

        int index = 0;

        for(int i=0; i<N; i++){
            if(find(edges[i][0]) == find(edges[i][1])){
                target[0] = edges[i][0];
                target[1] = edges[i][1];
                return target;
            }
            union(edges[i][0], edges[i][1]);
        }
        return target;
    }

    public void union(int x, int y){
        pre[find(x)] = find(y);
    }
    public int find(int x){
        if(pre[x]!=x)
            pre[x] = find(pre[x]);
        return pre[x];
    }
}
```
