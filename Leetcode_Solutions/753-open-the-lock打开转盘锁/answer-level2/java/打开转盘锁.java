#### 方法一：广度优先搜索

我们可以将 `0000` 到 `9999` 这 `10000` 状态看成图上的 `10000` 个节点，两个节点之间存在一条边，当且仅当这两个节点对应的状态只有 `1` 位不同，且不同的那位相差 `1`（包括 `0` 和 `9` 也相差 `1` 的情况），并且这两个节点均不在数组 `deadends` 中。那么最终的答案即为 `0000` 到 `target` 的最短路径。

我们用广度优先搜索来找到最短路径，从 `0000` 开始搜索。对于每一个状态，它可以扩展到最多 `8` 个状态，即将它的第 `i = 0, 1, 2, 3` 位增加 `1` 或减少 `1`，将这些状态中没有搜索过并且不在 `deadends` 中的状态全部加入到队列中，并继续进行搜索。注意 `0000` 本身有可能也在 `deadends` 中。

```Python [sol1]
class Solution(object):
    def openLock(self, deadends, target):
        def neighbors(node):
            for i in xrange(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i+1:]

        dead = set(deadends)
        queue = collections.deque([('0000', 0)])
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target: return depth
            if node in dead: continue
            for nei in neighbors(node):
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, depth+1))
        return -1
```

```Java [sol1]
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> dead = new HashSet();
        for (String d: deadends) dead.add(d);

        Queue<String> queue = new LinkedList();
        queue.offer("0000");
        queue.offer(null);

        Set<String> seen = new HashSet();
        seen.add("0000");

        int depth = 0;
        while (!queue.isEmpty()) {
            String node = queue.poll();
            if (node == null) {
                depth++;
                if (queue.peek() != null)
                    queue.offer(null);
            } else if (node.equals(target)) {
                return depth;
            } else if (!dead.contains(node)) {
                for (int i = 0; i < 4; ++i) {
                    for (int d = -1; d <= 1; d += 2) {
                        int y = ((node.charAt(i) - '0') + d + 10) % 10;
                        String nei = node.substring(0, i) + ("" + y) + node.substring(i+1);
                        if (!seen.contains(nei)) {
                            seen.add(nei);
                            queue.offer(nei);
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2 * A^N + D)$。我们用 $A$ 表示数字的个数，$N$ 表示状态的位数，$D$ 表示数组 `deadends` 的大小。在最坏情况下，我们需要搜索完所有状态，状态的总数为 $O(A^N)$。对于每个状态，我们要枚举修改的位置，需要 $O(N)$ 的时间，枚举后得到新的状态同样需要 $O(N)$ 的时间。

* 空间复杂度：$O(A^N + D)$，用来存储队列以及 `deadends` 的集合。