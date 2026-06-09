先贴代码再讲解
```
class Solution {
    private Queue<int[]> edge;
    final int[][] dxy = {{1,0},{0,1},{-1,0},{0,-1}};
    
    public int shortestBridge(int[][] A) {
        if(A.length == 0) return -1;
        edge = new LinkedList<>();
        int m = A[0].length;
        int n = A.length;
        firstLoop:
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(A[i][j] == 1){
                    findEdge(i, j, A);
                    break firstLoop;
                }
            }
        }
        while(true){
            if(edge.isEmpty()) return -1;
            int[] edgePos = edge.poll();
            int i = edgePos[0];
            int j = edgePos[1];
            for(int k = 0; k < 4; k ++){
                int x = i + dxy[k][0];
                int y = j + dxy[k][1];
                if(x < 0 || y < 0 || x >= n || y >= n) continue;
                if(A[x][y] == 1) {
                    return A[i][j] - 1;
                }if(A[x][y] == 0){
                    A[x][y] = A[i][j] + 1;
                    edge.add(new int[]{x, y});
                }
            }
        }
        
    }
    private void findEdge(int i, int j, int[][] A){
        A[i][j] = -1;
        for(int k = 0; k < 4; k ++){
            int x = i + dxy[k][0];
            int y = j + dxy[k][1];
            if(x < 0 || y < 0 || x >= A.length || y >= A[0].length)
                continue;
            if(A[x][y] == 0) {
                A[x][y] = 2;
                edge.add(new int[]{x, y});
            }
            else if(A[x][y] == 1) findEdge(x, y, A);
        }
    }
}
```
思路如下：
1. 首先找到A中的第一个1，表示这是第一个小岛的一个位置，然后在该坐标进行DFS搜索该岛的所有边缘坐标，遍历过程中，如果`A[x][y] == 0`，表示该点是边缘，标注`A[x][y] = 2`表示步长，然后加入边缘队列；如果`A[x][y] == 1`，表示还在岛内，标注为-1以和另一座岛作区分。
2. 对队列中的边缘坐标做BFS运算，i,j为队列中取出的边缘坐标，A[i][j]记录步长，如果下一个结点为1，表示已经找到了最短的路径，返回`A[i][j] - 1`(我们是从2开始记录步长的)，如果是0，`A[x][y] = A[i][j] + 1`表示该位置的步长。
3. 算法复杂度应该为O(M x N).
