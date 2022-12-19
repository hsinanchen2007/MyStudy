### 解题思路
1. 定义数据结构Node记录信息，进行节点排序
2. Collections.sort采用了 Comparator.comparingInt(crd -> crd.dist)，比较难理解，是IntelliJ Idea提示写出来的。
题目设陷阱：
1.输出的是坐标值，所以要先保留坐标值，如果通过数组下标进行换算就掉入陷阱。

### 代码

```java
class Solution {
   static class Node {
        int r;
        int c;
        int dist;

        private Node(int r, int c, int dist) {
            this.r = r;
            this.c = c;
            this.dist = dist;
        }
    }

    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        List<Node> result = new ArrayList();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int dist = Math.abs(r - r0) + Math.abs(c - c0);
                result.add(new Node(r, c, dist));
            }
        }
        Collections.sort(result, Comparator.comparingInt(crd -> crd.dist));
        int[][] ans = new int[result.size()][2];
        int index = 0 ;
        for(Node item:result) {
            int[] crd = new int[2];
            crd[0] = item.r;
            crd[1] = item.c;
            ans[index++] = crd;
        }
        return ans;
    }
}
```