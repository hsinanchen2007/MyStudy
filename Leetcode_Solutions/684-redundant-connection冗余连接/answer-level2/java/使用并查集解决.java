### 解题思路
使用并查集，这是连通性问题，多的一条边表示已经在相同的集合中了，通过是否isconnected来判定，遍历完所有的边，用existi记录最后一条已经在集合中的边，最后返回即可。
这里需要注意的是：初始集合的大小，需要N+1，因为i从0开始，最大需要到N，所以整个parent数据的长度需要N+1

### 代码

```java
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int len = edges.length;
        int existi = 0;
        int[] parent = new int[len+1];
        for (int i=0; i< len+1; ++i) {
            parent[i] = i;
        }

        for (int i= 0; i< len; ++i)  {
            if (isConnected(edges[i][0],edges[i][1], parent)) {
                existi = i;
                continue;
            }
            
            union(edges[i][0],edges[i][1], parent);
        }
        
        return edges[existi];
    }
    
    private boolean isConnected(int x, int y, int[] parent) {
        return find(x, parent) == find(y, parent);
    }
    
    private void union(int x, int y, int[] parent) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py) {
            return;
        }
        
        parent[px] = py;
    }

    private int find(int y, int[] parent) {
        while (parent[y] !=y) {
            y = parent[y];
        }
        return y;
    }
}

执行用时 :1 ms, 在所有 Java 提交中击败了99.47%的用户
内存消耗 :39.4 MB, 在所有 Java 提交中击败了28.57%的用户

```