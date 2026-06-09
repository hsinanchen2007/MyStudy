### 解题思路
首先遍历节点，将边界上的节点和所有的水面同0相连接（这个可能不够严谨，将0当做了一个哑结点，换成row*col可能更严谨，但是能通过），然后将所有岛屿，即编号为1的节点连接，最后返回连通分量-1，因为所有的水面构成一个连接

### 代码

```java
class UnionFind{
    public int[] parents;   // 父节点
    public int[] size;     // 权重
    public int count;      // 连通分量个数

    public UnionFind(int n){
        count = n;
        parents = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    public int count() {
        return count;
    }

    public int find(int p) {
        validate(p);
        while (p != parents[p])
            p = parents[p];
        return p;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    private void validate(int p) {
        int n = parents.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));
        }
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parents[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parents[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }


}
class Solution {

    public int closedIsland(int[][] grid) {
        int row = grid.length;
        int col=grid[0].length;
        UnionFind uf = new UnionFind(row*col);
        //将所有水面连接
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    uf.union(i*col+j,0);
                }
            }
        }
        /*
         * 将边界同水面相连接
         */
        for(int i=0;i<col;i++){
            uf.union(i,0);
        }
        //防溢出
        if(row>1){
            for(int i=col*(row-1)-1;i<row*col;i++){
            uf.union(i,0);
            }
        }

        for(int i=0;i<row*col;i+=col){
            uf.union(i,0);
        }
        if(col>1){
            for(int i=col-1;i<row*col;i+=col){
                uf.union(i,0);
            }
        }
        
        //链接陆地，因为遍历有先后性，所以只考虑了上方和左方的陆地
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    if(i>0&&grid[i-1][j]==0){
                        uf.union((i-1)*col+j,i*col+j);
                        
                    }
                    if(j>0&&grid[i][j-1]==0){
                        uf.union((i)*col+j-1,i*col+j);
                    }
                }
            }
        }
        
        return uf.count-1;
    }
    
}
```