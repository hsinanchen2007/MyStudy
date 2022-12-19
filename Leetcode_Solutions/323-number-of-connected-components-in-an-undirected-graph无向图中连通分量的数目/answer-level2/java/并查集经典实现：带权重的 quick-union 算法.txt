有关并查集的题目，一般会给出提示题目中的关系满足等价关系，即具有自反性、对称性、传递性；输入一系列的整数对<p,q>...表示节点p与节点q具有等价关系。从数学的角度看所有输入的整数属于不同的集合，处理<p,q>时判断是否属于相同的集合，如果不是就将两个集合归并。
至于求无向图的连通分量，简单分析一下显然节点之间的“连接”满足等价关系：
自反性，p和p是连接的；
对称性，如果p与q是连接的，那么q与p也是连接的；
传递性，如果p与q连接且q与r连接，那么p与r也是连接的。
```
// 带权的 quick union 算法的模板
class Solution {
    private int[] id ;  // id[index] 表示第 index 个节点的父亲，并查集看成森林
    private int count ; // 等价类的数量
    private int[] w ;   // 根节点对应的分量的大小
    public Solution(){}
    public Solution(int n){
        id = new int[n];
        w = new int[n];
        count = n;
        for(int i = 0;i < n;i++){
            w[i] = 1; 
            id[i] = i; // 初始化有 n 个等价类
        }
    }

    int count(){
        return count;
    }
    // find 操作返回该节点的根节点作为等价类标识符，查找的复杂度与树的高度有关
    public int find(int p){
        while(p != id[p]){
            p = id[p];
        }
        return p;
    }
    // union 操作通过改变父节点的指向实现
    public void union(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        // 根据权重优化：避免树高增长过快总是把小树接到大树上
        if(w[rootP] < w[rootQ]){
            id[rootP] = rootQ;
            w[rootQ] += w[rootP];      
        }else{
            id[rootQ] = rootP;
            w[rootP] += w[rootQ];   
        }
        count --;
    }
    // 并查集经典的题目求图的连通分量
    public int countComponents(int n, int[][] edges) {
        Solution uf = new Solution(n);
        for(int[] e:edges){
            uf.union(e[0],e[1]);
        }
        return uf.count();
    }
}
```
