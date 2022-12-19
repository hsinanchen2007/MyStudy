**BFS**

原题可以转化为在最大深度为K + 1的情况下去尝试访问目标节点， 找出其中最优（最低价格）的方案。

细节：

-- 初始深度为-1
-- 为了记录访问至当前节点的开销可以定义一个<code>Node</code>这么一个类来记录当前节点的<code>idx</code>及<code>price </code>

另外就是常规的优化，即如果目前开销已经高于其他方案，哪怕没有达到最大深度，当前节点的子节点做减枝处理。

```
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        /**********************************************
        Details :
        1. the initial depth should not be 0
        1. getOrDefault
        2. when no valid path
        *************************************************/
        
        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int[] arr : flights) {
            List<int[]> list = map.getOrDefault(arr[0], new ArrayList<>());
            list.add(arr);
            map.put(arr[0], list);
        }
        int maxDeps = K + 1;
        int min = Integer.MAX_VALUE;
        
        Queue<Node> queue = new  LinkedList<>();
        int deps = -1;
        queue.offer(new Node(0, src));
        
        while (!queue.isEmpty()) {
            deps++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                if (deps <= maxDeps) {
                    if (node.idx == dst) {
                        min = Math.min(node.price, min);
                    } else {
                        if (deps < maxDeps && node.price < min) {
                            for (int[] arr : map.getOrDefault(node.idx, new ArrayList<>())) {
                                if (arr[2] + node.price < min) {
                                    queue.offer(new Node(node.price + arr[2], arr[1]));
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return min == Integer.MAX_VALUE ? -1 : min;
            
    }
    
    private class Node {
        int price;
        int idx;
        public Node(int pri, int index) {
            idx = index;
            price = pri;
        }
    }
}
```
<pre>
执行用时 :11 ms, 在所有 Java 提交中击败了90.91% 的用户
内存消耗 :37.9 MB, 在所有 Java 提交中击败了96.88%的用户
</pre>

**复杂度**
Space: O (n ^ 2)
Runtime: O (n ^ 2)

