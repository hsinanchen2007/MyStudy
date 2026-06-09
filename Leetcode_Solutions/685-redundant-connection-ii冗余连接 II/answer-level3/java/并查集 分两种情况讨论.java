详见代码
```
class Solution {
    int[] parent;   //各节点父节点
    public int[] findRedundantDirectedConnection(int[][] edges) {
        parent = new int[edges.length+1];
        for(int i=0; i<parent.length; i++) {
            parent[i] = i;  //默认父节点为自己
        }
        /*
        conflict说明发生冲突，记录下边的序号
        冲突举例[[2,1],[3,1],[1,4],[4,2]]
        由于parent[1]=2,无法再将3赋给parent[1]
        即当前edges[conflict][1]的父节点已经不为自己，此时在循环中直接跳过
        */
        int conflict = -1; 
        /*
        与conflict相对,图中不发生冲突，所有节点都有唯一父节点但成环，如题中示例2，
        用来记录成环边的序号
        */
        int noconflict = -1;
        for(int i=0; i<edges.length; i++) {
            if(parent[edges[i][1]] != edges[i][1]) {
                conflict = i;
                continue;
            }
            /*
            如果不发生冲突，可以找到成环边，并记录。
            注意noconflict == -1不可少否则一旦成环后面find会造成死循环，
            之所以仍不跳出是因为后面仍有可能有边造成冲突，导致该记录无意义
            */
            if(conflict == -1 && noconflict == -1 && find(edges[i][0]) == find(edges[i][1])) noconflict = i;
            parent[edges[i][1]] = edges[i][0];  //记录父节点
        }
        //如果未冲突，直接返回成环边
        if(conflict == -1) return edges[noconflict];
        /*
        否则进行判断：
        由于未添加冲突边，如果当前图有环，则说明答案是与之相对的另一条边
        否则就是该冲突边
        */
        if(hasCircle(edges[conflict][1])) {
            int[] res = new int[2];
            res[1] = edges[conflict][1];
            res[0] = parent[edges[conflict][1]];
            return res;
        }
        else return edges[conflict];
    }
    private boolean hasCircle(int i) {
        int v = i;
        while(parent[i] != i) {
            if(parent[i] == v) return true;
            i = parent[i];
        }
        return false;
    }
    private int find(int n) {
        while(n != parent[n]) n = parent[n];
        return n;
    }
}
```
