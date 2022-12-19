贴个比较挫的代码，核心思路：
1、先找到入度为0，出度大于0的根节点（这题的结构每个节点最多出度为2，不必考虑多叉树），根节点只能有一个，
2、判断图中有没有环，无环就是二叉树了

```
class Solution {
     public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
    //找到根节点
    int rootCount = 0;
    int rootPosi = 0;
    for (int i = 0; i < n; i++) {
      //没有出去的边
      if (leftChild[i] == -1 && rightChild[i] == -1) {
        continue;
      }
      //没有进去的边
      boolean root = true;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (leftChild[j] == i || rightChild[j] == i) {
            root = false;
          } 
        }
      }
      if (root) {
        rootPosi = i;
        rootCount++;
      }
    }
    //只能有一个根节点
    if (rootCount != 1) {
      return false;
    }
    boolean[] visited = new boolean[n];
    List<Boolean> alt = new ArrayList<>();
    //判断有没有环
    dfs(visited, leftChild, rightChild, rootPosi, n, alt);
    if (alt.size() > 0) {
      return false;
    }

    return true;
  }

 public void dfs(boolean[] visited, int[] left, int[] right, int p, int n,
      List<Boolean> alt) {
    if (p < n && visited[p] == false) {
      visited[p] = true;
      if (left[p] != -1) {
        dfs(visited, left, right, left[p], n, alt);
      }
      if (right[p] != -1) {
        dfs(visited, left, right, right[p], n, alt);
      }
    } else {
      alt.add(false);
    }
  }
}
```
