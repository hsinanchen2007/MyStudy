### 解题思路
设置一个数组parent,里面存储的是每个节点对应的父节点,通过两层循环不断遍历grid中的每个字符,如果字符为1,则counts++;然后判断是否需要与该位置的左位置和上位置union,如果需要union,先判断两者的根节点是否相同,如果不同,则counts--;最后返回counts即可

### 代码

```java
import java.util.HashSet;

/**
 * 复习
 * 并查集
 */
public class Solution {

    // 构建并查集
    private int[] parent;  // 定义索引对应的集合，如果是水则定义成-1
    private int[] rank;    // 每个索引对应的秩
    private int rows;
    private int cols;
    private int counts;

    public int numIslands(char[][] grid) {
        if(grid.length == 0){
            return 0;
        }

        // 对parent和rank进行初始化
        rows = grid.length;
        cols = grid[0].length;
        parent = new int[rows*cols];
        rank = new int[rows*cols];

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int coord = coordinate(i, j);
                rank[coord] = 1;
                if(grid[i][j] == '0'){
                    parent[coord] = -1;
                }else {
                    counts ++;
                    parent[coord] = coord;
                    // 对上左进行合并
                    if(i != 0 && grid[i-1][j] == '1'){
                        union(coord, coordinate(i-1, j));
                    }
                    if(j != 0 && grid[i][j-1] == '1'){
                        union(coord, coordinate(i, j-1));
                    }
                }
            }
        }

        return counts;
    }

    // 得到坐标对应的索引
    private int coordinate(int i, int j){
        return i*cols+j;
    }

    // 查找索引i对应的根节点  前提是陆地
    private int find(int i){
        while(i != parent[i]){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    // 对两个索引进行union
    private void union(int i, int j){
        int i_root = find(i);
        int j_root = find(j);

        if(i_root == j_root){
            return;
        }

        if(rank[i_root] == rank[j_root]){
            // 此时随便谁指向谁
            parent[i_root] = j_root;
            rank[j_root] += 1;  // j_root的秩或者可以说高度增加1
        }
        else if(rank[i_root] > rank[j_root]){
            parent[j_root] = i_root;
        }
        else {
            parent[i_root] = j_root;
        }

        counts --;
    }
}

```