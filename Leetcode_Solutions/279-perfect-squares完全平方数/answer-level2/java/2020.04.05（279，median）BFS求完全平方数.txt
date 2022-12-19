### 解题思路
本题使用 `BFS` 来求解完全平方数

- 首先用队列来暂存**每层的元素**，用 `set` 来**排除重复的元素**，防止每层有相同的平方数出现干扰判断

- 主要思想是将每层的节点依次减 1, 4, 9...得到下一层元素，以此类推直到某一层出现了 `0`

- 此时的层数就是我们要找的**最小个数**的完全平方数，返回该层的**层数**即可。

### 代码

```java []
class Solution {
    public int numSquares(int n) {
        Queue<Integer> queue = new LinkedList<>();
        // 创建 set 来存放非重复的元素
        Set<Integer> visited = new HashSet<>();
        queue.add(n);
        // 定义 level 记录完全平方数的个数
        int level = 0;
        while (!queue.isEmpty()) {
            int len = queue.size();
            // 每次有元素入队就代表还有剩余子平方数
            level++;
            for (int i = 0; i < len; i++) {
                int node = queue.poll();
                // 从 1 开始取，每次拿平方数来比较
                for (int j = 1; j * j <= node; j++) {
                    // 用当前结点减去平方数 1,4,9...
                    int next = node - j * j;
                    // 找完所有的平方数即可返回
                    if (next == 0) {
                        return level;
                    }
                    // 如果 set 里面没有存放当前元素，则可以入队,入 set
                    if (!visited.contains(next)) {
                        queue.add(next);
                        visited.add(next);
                    }
                }
            }
        }
        return 0;
    }
}
```