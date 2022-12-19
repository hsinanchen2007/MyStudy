java 基于并查集来解决;
思路 copy 自  [c++, 并查集](https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/cbing-cha-ji-by-liyupi/)
```
class Solution {
    public int regionsBySlashes(String[] grid) {
        if (grid == null || grid.length == 0 || grid[0] == null) {
            return 0;
        }

        int N = grid.length;
        MyUF myUF = new MyUF(N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int start = 4 * (i*N + j);
                char elem = grid[i].charAt(j);
                if (elem == '/') {
                    myUF.union(start, start+1);
                    myUF.union(start+2, start+3);
                } 
                if (elem == '\\') {
                    myUF.union(start, start + 3);
                    myUF.union(start + 1, start + 2);
                } 
                if (elem == ' ') {
                    myUF.union(start, start+1);
                    myUF.union(start+1, start+2);
                    myUF.union(start+2, start+3);
                }

                // 边界处理

                // 从第二行(i > 0) 开始将上下相邻元素进行连通
                if (i > 0) {
                    myUF.union(start, start - N * 4 + 2);
                }
                
                // 从第二列(j > 0) 开始将左右相邻元素进行连通(union)
                if (j > 0) {
                    myUF.union(start -1, start + 1);
                }
            }
        }
        return myUF.connectedCounter();
    }
}

class MyUF {
    // ids[i] 记录的是数值 i 的根节点
    private int [] ids;

    // 记录并查集集合总数
    private int counter;

    public MyUF(int N) {
        counter = N * N * 4;
        ids = new int [N*N*4];
        for (int i = 0; i < N*N*4; i++) {
            ids[i] = i;
        }
    }

    // 将 a,b 元素所在的集合合二为一
    public void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return;
        }
        ids[rootA] =  rootB;

        // 每次合并, 元素数目减少 1 个
        counter -= 1;
    }

    public int connectedCounter() {
        return counter;
    }

    // 路径压缩
    private int find(int a) {
        // 说明: 
        // 如果当前节点的父节点不是它自己, 这个节点不是根节点则递归方式不断找其父节点
        // 最终得到根节点, 将根节点逐一回溯, 最终每层递归的父节点都被赋值为根节点;
        // 如果当前节点的父节点是自己, 当前节点就是根节点, 直接返回;
        return ids[a] != a ? ids[a] = find(ids[a]) : a;
    }
}
```
