### 解法一 深度优先遍历
1.我们遍历二维网格，在遇到1的时候增加一次岛屿的数量。
2.然后将与当前1相连的所有为1的都变为0,这样这个一块岛屿就从grid中移除变为水了。
```
class Solution {
    
    public int numIslands(char[][] grid) {
        if(grid.length==0) return 0;
        int numIslands=0;
        for(int col=0;col<grid.length;col++){
            for(int row=0;row<grid[col].length;row++){
                if(grid[col][row]=='1'){
                    //如果遇到1，说明是岛屿，递归将岛屿周围的岛都变为0，
                    numIslands++;
                    setlandToWater(col,row,grid);
                }
            }
        }
        return numIslands;
    }

    private void setlandToWater(int col,int row,char[][] grid){
        if(col<0 || col>=grid.length || row <0 || row >=grid[col].length) {
            //越界检查
            return;
        }
        if(grid[col][row]=='0') return;
        grid[col][row]='0';
        //遍历四周
        setlandToWater(col-1,row,grid);
        setlandToWater(col+1,row,grid);
        setlandToWater(col,row-1,grid);
        setlandToWater(col,row+1,grid);
    }
}
```
### 解法二  并查集
```
class Solution {
    //并查集
    public class Union{
        int roots[];
        int count;
        public Union(int n,char[][] grid){
            roots=new int[n];
            //初始化并查集，自己指向自己,只需要初始化1所对应的位置.
            for(int row=0;row<grid.length;row++){
                for(int col=0;col<grid[row].length;col++){
                    if(grid[row][col]=='1'){
                        int index=row*grid[row].length+col;
                        roots[index]=index;
                        //每次找到一个1就加一，count就代表1的数量，单独岛的数量，
                        //然后再下面合并的时候再进行减1，最终得到岛屿的数量
                        count++;
                    }
                }
            }
        }
        //查找某个root，并做状态压缩
        public int findRoot(int i){
            int root=i;
            while(roots[root]!=root){//如果不等于自身，则说明有连接的节点，往上找
                root=roots[root];
            }
            //上面一步找到了跟根节点，现在我们要将这条链路上的节点，都指向根节点，缩短链路的长度
            while(i!=roots[i]){
                int temp=roots[i];//记录一下当前位置的指向，
                roots[i]=root;//更新指向，指向根节点
                i=roots[i];
            }
            return root;
        }

        public boolean isConnect(int p,int q){
            return findRoot(p)==findRoot(q);
        }
        //合并两个节点
        public void union(int p,int q){
            int rootP=findRoot(p);//分别找到每个点对应的根节点
            int rootQ=findRoot(q);
            if(rootP!=rootQ){
                roots[rootP]=rootQ;
                //因为count是代表的单独岛的数量，所以每合并一个岛就需要减1.
                count--;
            }
        }
    }
    public int numIslands(char[][] grid) {
        if(grid.length==0) return 0;
        int rowLength=grid.length;
        int colLength=grid[0].length;
        Union union=new Union(rowLength*colLength,grid);
        for(int row=0;row<rowLength;row++){
            for(int col=0;col<colLength;col++){
                if(grid[row][col]=='1'){
                    //因为我们是从上到下，从左到右遍历的，所以不需要判断四周，上跟左前面已经遍历过了。
                    //判断当前岛屿右边，以及下面的是否是岛屿，如果是连接岛屿。
                    if(row+1<rowLength && grid[row+1][col]=='1'){
                        union.union(row*colLength+col,(row+1)*colLength+col);
                    }
                    if(col+1<colLength && grid[row][col+1]=='1'){
                        union.union(row*colLength+col,row*colLength+col+1);
                    }
                }
            }
        }
        return union.count;
    }
}
```

