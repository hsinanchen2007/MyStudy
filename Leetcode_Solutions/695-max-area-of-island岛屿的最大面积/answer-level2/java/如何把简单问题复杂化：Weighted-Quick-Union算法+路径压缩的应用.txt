Union-Find算法可将几何上的连通关系，用树的形式抽象描述。因此不仅可以求解**连通集大小**问题，还能解决许多其他问题的解：
1. 给定点A、点B，问**两点之间是否连通**（直接调用find(point A, point B),返回true or fause)
2. 求整个图上的**连通集个数**（Union类再添加私有变量count=所有点的个数，每次union成功-1即可）
3. 著名的**percoltion**问题，即矩形的上边与下边是否有一条连通通路，或迷宫出入口是否连通的问题

并查集是一种树形的数据结构，其可用数组或unordered_map表示：

![116770-20190420113129879-294967307.png](https://pic.leetcode-cn.com/59bfc8b05bce11efd0a7478d70af8851a7e0534f46eb487da5aeef6cee189fa7-116770-20190420113129879-294967307.png)

Find操作即查找元素的root，当两元素root相同时判定他们属于同一个子集；Union操作即通过修改元素的root(或修改parent)合并子集，下面两个图展示了id[6]由6修改为9的变化：

![116770-20190420113322340-1698972577.png](https://pic.leetcode-cn.com/8b209de59884cbe430d673c5099865a434492bfe23744a506d1fe82d9ea8f220-116770-20190420113322340-1698972577.png)

![116770-20190420113755909-1048724107.png](https://pic.leetcode-cn.com/b9fbd53752e49a74a09caac201216b04880f55b2f0c0233de87cd56d43486186-116770-20190420113755909-1048724107.png)


Quick-Union算法的优化：路径压缩，每次调用find，将find的结点直接连接到root结点上，对于复杂图可以有效提高后续的查找效率，这里因为问题的规模太小了，就把路径压缩的代码注释了，对于小规模问题使用Path Compression会适得其反。

```
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        if(row <= 0 || col <= 0) return 0;

        WeightedQuickUnion wqu = new WeightedQuickUnion(row, col);
        boolean all_zero = true;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 1) {
                    all_zero = false;
                    if(i-1>=0 && grid[i-1][j]==1)
                        wqu.union((i-1)*col+j, i*col+j);
                    if(i+1<row && grid[i+1][j]==1)
                        wqu.union((i+1)*col+j, i*col+j);
                    if(j-1>=0 && grid[i][j-1]==1)
                        wqu.union(i*col+j-1, i*col+j);
                    if(j+1<col && grid[i][j+1]==1)
                        wqu.union(i*col+j+1, i*col+j);
                }
            }
        }
        if(all_zero) return 0;
        else return wqu.maxSize();
    }
}

class WeightedQuickUnion {
    private int[] id;
    private int[] sz;

    public WeightedQuickUnion(int M, int N) {
        id = new int[M*N];
        for(int i=0;i<id.length;i++) id[i] = i;
        sz = new int[M*N];
        for(int i=0;i<sz.length;i++) sz[i] = 1;
    }

    public int maxSize() {
        int max = 0;
        for(int n:sz) {
            if(n>max) max = n;
        }
        return max;
    }

    // find节点p的根节点
    public int find(int p) {
        int root = p;
        while (root != id[root])
            root = id[root];
        // 使用Path Compression后的动态Union-Find算法，find可达到接近o(1)级别

        // Path Compression
        // while (p != root) {
        //     int newp = id[p];
        //     id[p] = root;
        //     p = newp;
        // }
        return root;
    }

    public void union(int p, int q) {
        // 若p和q的根节点相同，说明属于一个连通集
        int i = find(p);
        int j = find(q);
        if(i == j) return;
        // 第二个优化小trick，永远把小数合并到大树上，防止树过于不平衡，导致find变成o(n)数量级
        // 加了多这一行，可以保证o(logn)的find复杂度，性能至少提高20%
        // 如果采用了路径压缩，可达非常非常接近o(1)级别，（感兴趣可以百度反Ackermann函数log*，几乎是常数级别）
        if(sz[i]<sz[j]) { id[i]=j; sz[j]+=sz[i];}
        else            { id[j]=i; sz[i]+=sz[j];}
    }
}
```
