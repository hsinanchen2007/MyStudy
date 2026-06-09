```
class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> graph = new HashMap<>(); // map构造图(邻接表)
        for (List<String> list : tickets) {
            if (!graph.containsKey(list.get(0))) {
                graph.put(list.get(0), new PriorityQueue<String>());
            }
            graph.get(list.get(0)).offer(list.get(1));
        }
        List<String> ret = new ArrayList<>();
        dfs(tickets, graph, "JFK", ret);
        return ret;
    }

    public void dfs(List<List<String>> tickets, Map<String, PriorityQueue<String>> graph, String start, List<String> ret) {
        PriorityQueue<String> endQueue = graph.get(start);
        while (endQueue != null && endQueue.size() > 0) {
            String end = endQueue.poll();
            dfs(tickets, graph, end, ret);
        }
        ret.add(0, start); // 最后插入结点
    }
}
```
