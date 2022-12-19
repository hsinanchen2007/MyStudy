```
class Solution {
        public Node construct(int[][] grid) {
            return dfs(grid,0,0,grid.length);
        }
        //将大矩形拆分成小矩形
        private Node dfs(int[][] grid, int i, int j, int len) {
            if (len == 1)return new Node(grid[i][j] == 1,true,null,null,null,null);
            return help(dfs(grid,i,j,len/2),dfs(grid,i+len/2,j,len/2),dfs(grid,i,j+len/2,len/2),dfs(grid,i+len/2,j+len/2,len/2));
        }
        
        private Node help(Node... node) {
            boolean val = node[0].val;
            boolean isLeaf = true;

            for (Node n:node){
                if (val != n.val||n.isLeaf == false){
                    isLeaf = false;
                }
            }

            if (isLeaf){
                return new Node(val,isLeaf,null,null,null,null);
            }else {
                return new Node(val,isLeaf,node[0],node[1],node[2],node[3]);
            }
        }
    }
```
