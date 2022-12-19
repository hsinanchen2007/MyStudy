### 解题思路
1、先设置几个私有函数，
    coordinate():将坐标点转换成对应于parent的索引
    isBounary():判断该索引是否是边界点
    find():查找索引对应的根索引
    union():将两个索引进行合并，合并的条件是，两个索引对应于board的值都是O，然后将非边界根节点指        向边界根节点，如果都是非边界根节点，则随便谁指向谁
2、进行两层循环，不断更新parent中的每个索引对应的值，初始值为该索引，如果该索引对应的board位置的值为'O'且左位置为'O'，则合并；如果该索引对应的board位置的值为'O'且上位置为'O'，则合并；
3、进行两层循环，对board进行遍历，如果该位置为'O'，而且该位置对应的根节点不是边界点，则修改为'X';

### 代码

```java
/**
 * 并查集
 */
public class Solution {

    // 构建并查集
    int rows;
    int cols;
    private int[] parent;

    public void solve(char[][] board) {

        if(board.length == 0){
            return;
        }

        rows = board.length;
        cols = board[0].length;
        parent = new int[rows*cols];

        // 跟parent赋初值以及不断对O进行union
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int coord = coordinate(i, j);
                parent[coord] = coord;  // parent中每个索引对应的初始根节点为索引本身
                if (board[i][j] == 'O') {
                    // 进行union的条件  上 左
                    if(i != 0 && board[i-1][j] == 'O'){
                        union(coord, coordinate(i-1, j));
                    }
                    if(j != 0 && board[i][j-1] == 'O'){
                        union(coord, coordinate(i, j-1));
                    }
                }
            }
        }

        // 根据parent对board中的O进行更改
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == 'O' && !isBoundary(find(coordinate(i, j)))){
                    board[i][j] = 'X';
                }
            }
        }

    }

    // 获得坐标(i, j)对应于一维的索引
    private int coordinate(int i, int j){
        return i*cols+j;
    }

    // 判断该节点是否边界点
    private boolean isBoundary(int i){
        // i对应的坐标值
        int coord_i = i/cols;
        int coord_j = i%cols;

        if(coord_i==0 || coord_i==rows-1 || coord_j==0 || coord_j==cols-1){
            return true;
        }
        return false;
    }

    // 找到索引i对应的根节点
    private int find(int i){
        if(i != parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }


    // 对两个节点进行union
    private void union(int i, int j){
        int i_root = find(i);
        int j_root = find(j);

        if(i_root != j_root){
            // 由非边界点指向边界点  如果两个节点都是非边界点，那么随便谁指向谁
            if(isBoundary(i_root)){
                parent[j_root] = i_root;
            }
            else if(isBoundary(j_root)){
                parent[i_root] = j_root;
            }
            else {
                parent[i_root] = j_root;
            }
        }
    }
}

```