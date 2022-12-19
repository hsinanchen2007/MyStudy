### 解题思路
编写一个内部类，定义每个点的属性，坐标和离陆地的最远距离。

### 代码

```java
class Solution {
    
    int m;
    int n;
    
    private class Node{
        int x;
        int y;
        int far;  //定义该点距离出发点大陆的距离
        public Node(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
    
    public boolean check(int x,int y){
        if(x<0 || x>=m || y<0 || y>=n){
            return false;
        }
        return true;
    }
    
    public int maxDistance(int[][] grid) {
        //首先遍历grid找出所有为1的元素
        
        m = grid.length;
        n = grid[0].length;
        
        Queue<Node> queue = new LinkedList<>();
        
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    queue.add(new Node(i,j));
                }
            }
        }
        return BFS(queue,grid);
    }
    
    public int BFS(Queue<Node> queue,int[][] grid){
        int[] dx = {-1,1,0,0};
        int[]dy = {0,0,-1,1};
        boolean hasOcean = false;
        Node newNode = null;
        while(!queue.isEmpty()){
            Node curNode = queue.poll();
            for(int k=0;k<4;k++){
                int newX = curNode.x+dx[k];
                int newY = curNode.y+dy[k];
                if(check(newX,newY) && grid[newX][newY]==0){
                    newNode = new Node(newX,newY);
                    newNode.far = curNode.far+1;
                    grid[newX][newY] = 1;
                    hasOcean = true;
                    queue.add(newNode);
                }
            }   
        }
        if(newNode == null || !hasOcean){
            return -1;
        }
        return newNode.far;
    }
}
```