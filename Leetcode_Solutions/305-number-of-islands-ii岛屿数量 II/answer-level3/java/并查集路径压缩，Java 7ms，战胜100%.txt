通过本题学习了并查集的使用，学会了并查集后，这个题目还是比较容易的，参考下面的代码和注释：

![image.png](https://pic.leetcode-cn.com/1dda40c9a31fe61fe921e701cc3c7c4f0cd7695ac3cad589e40581ab4ea79de3-image.png)


```java
class Solution {

    //存储地图，岛屿为true，海水为false：
    boolean[][] matrix;
    //存储每个节点的父节点：
    int[] parents;
    //存储当前海岛数目：
    int res=0;

    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        List<Integer> list = new ArrayList<>(positions.length);
        parents = new int[m*n];
        matrix = new boolean[m][n];
        for (int[] position : positions) {
            //如果当前位置已经是海岛，直接添加结果continue：
            if (matrix[position[0]][position[1]]) {
                list.add(res);
                continue;
            }
            //当前位置置为海岛：
            matrix[position[0]][position[1]]=true;
            //合并当前位置与周边位置：
            merge(position[0], position[1], m, n, matrix);
            list.add(res);
        }
        return list;
    }

    int findRoot(int i, int j, int m, int n) {
        int ind=i*n+j;
        //并查集查询父节点，并进行路径压缩：
        while (parents[ind]!=ind) {
            parents[ind]=parents[parents[ind]];
            ind=parents[ind];
        }
        return ind;
    }

    void merge(int i, int j, int m, int n, boolean[][] matrix) {
        int ind=i*n+j;
        //海岛数加一：
        res++;
        //默认当前位置的父节点是自己：
        parents[ind]=ind;
        //合并上一行海岛：
        if (i>0 && matrix[i-1][j]) {
            //更新当前位置父节点：
            parents[ind]=findRoot(i-1, j, m, n);
            //海岛数减一：
            res--;
        }
        //合并下一行海岛：
        if (i<m-1 && matrix[i+1][j]) {
            int root = findRoot(i+1,j,m,n);
            //如果下一行位置的根节点不是当前位置的根节点，则合并：
            if (root!=parents[ind]) {
                parents[root]=parents[ind];
                res--;
            }
        }
        //逻辑和上面一样了：
        if (j>0 && matrix[i][j-1]) {
            int root=findRoot(i,j-1,m,n);
            if (root!=parents[ind]) {
                parents[root]=parents[ind];
                res--;
            }
        }
        //同上：
        if (j<n-1 && matrix[i][j+1]) {
            int root=findRoot(i,j+1,m,n);
            if (root!=parents[ind]) {
                parents[root]=parents[ind];
                res--;
            }
        }
    }
}
```
