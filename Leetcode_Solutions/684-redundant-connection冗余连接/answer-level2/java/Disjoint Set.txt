1. 可以用topological排序，复杂度高一些
2. 可以用Disjoint Set
其中涉及到的优化是在union两部分内容时，具体是x来Union到y还是y来union到x需要考虑各自大小。

```
class Solution {

    public int[] findRedundantConnection(int[][] edges) {
        int max = edges.length;
        int[] parent = new int[max+1];
        int[] size = new int[max+1];
        Arrays.fill(size, 1);
        for (int i = 1; i <= max; i++) {
            parent[i] = i;
        }
        for (int[] arr : edges) {
            if (find(parent[arr[0]], parent) == find(parent[arr[1]], parent)) return arr;
            union(arr[0], arr[1], parent, size);
        }
        return edges[edges.length-1];
    }
    
    void union(int x, int y, int[] parent, int[] size) {
        int left = find(x, parent);
        int right = find(y, parent);
        if (size[left] > size[right]) {
            parent[right] = left;
            size[left] += size[right];
            size[right] = 0;
        }
        else {
            parent[left] = right;
            size[right] += size[left];
            size[right] = 0;
        }
    }
    
    int find(int x, int[] parent) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return parent[x];
    }
  
}
```

执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :36.1 MB, 在所有 java 提交中击败了96.15%的用户
