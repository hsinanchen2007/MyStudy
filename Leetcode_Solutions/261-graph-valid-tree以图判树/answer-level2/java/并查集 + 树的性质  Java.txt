### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public boolean validTree(int n, int[][] edges) {

		// 树的性质！
    if (edges.length != n - 1) return false;

    DisjointSet set = new DisjointSet(n);

    for (int[] edge : edges) {
      set.union(edge[0], edge[1]);
    }

    return set.size == 1;
  }

  class DisjointSet {
    int size;
    int[] parent;

    DisjointSet(int N) {
      size = N;
      parent = new int[N];

      for (int i = 0; i < N; i++)
        parent[i] = i;
    }

    private void union(int a, int b) {
      int ap = find(a);
      int bp = find(b);
      if (ap != bp) {
        parent[ap] = bp;
        size--;
      }
    }

    private int find(int a) {
      while (a != parent[a])
        a = parent[a];
      return a;
    }
  }
}

```