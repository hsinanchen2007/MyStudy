### 解题思路
1. 首先应该能想到用构建图的方式来解决问题。然后关键是要构建双向图，因为按照题意，单向可推出反向的结果。
2. 然后要构建一个Edge类，来保存有向边的信息。然后基于Edge类，使用HashMap和List构建图。
3. 得到图之后，就可以使用bfs和dfs来解决问题了。

### 代码

```java
class Solution {
    Map<String, List<Edge>> map;
    List<String> visited;
    double[] res;
    
    private class Edge{
        String from;
        String to;
        double val;

        public Edge(String from, String to, double val){
            this.from = from;
            this.to = to;
            this.val = val;
        }
    }


    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        map = new HashMap<>();
        for(int i = 0; i < equations.size(); i++){
            List<String> edge = equations.get(i);
            String v1 = edge.get(0);
            String v2 = edge.get(1);
            double val = values[i];

            List<Edge> v1Edges = map.get(v1);
            if(v1Edges == null){
                v1Edges = new ArrayList<>();
                map.put(v1, v1Edges);
            }
            v1Edges.add(new Edge(v1, v2, val));
            List<Edge> v2Edges = map.get(v2);
            if(v2Edges == null){
                v2Edges = new ArrayList<>();
                map.put(v2, v2Edges);
            }
            v2Edges.add(new Edge(v2, v1, 1.0/val));
        }

        res = new double[queries.size()];
        visited = new ArrayList<>();
        for(int i = 0; i < queries.size(); i++){
            List<String> query = queries.get(i);
            String from = query.get(0);
            String to = query.get(1);
            visited.clear();
            res[i] = bfs(from, to, visited);
        }
        return res;
    }

    private double bfs(String from, String to, List<String> visited){
        if(!map.containsKey(from) || !map.containsKey(to)) return -1.0;
        if(from.equals(to)) return 1.0;
        Queue<Pair<String, Double>> queue = new LinkedList<>();
        queue.offer(new Pair(from, 1.0));
        
        while(!queue.isEmpty()){
            Pair<String, Double> cur = queue.poll();
            visited.add(from);
            List<Edge> edges = map.get(cur.getKey());
            if(edges == null || edges.size() == 0) return -1.0;
            for(Edge edge : edges)
                if(!visited.contains(edge.to)){
                    if(to.equals(edge.to)) return edge.val * cur.getValue();
                    queue.offer(new Pair(edge.to, cur.getValue()*edge.val));
                }
        }
        return -1.0;
    }

    private double dfs(String from, String to, List<String> visited){
        if(!map.containsKey(from) || !map.containsKey(to)) return -1.0;
        visited.add(from);
        if(from.equals(to)) return 1.0;

        List<Edge> fromEdges = map.get(from);
        if(fromEdges == null || fromEdges.isEmpty()) return -1.0;

        for(Edge edge : fromEdges){
            if(visited.contains(edge.to)) continue;
            double res = dfs(edge.to, to, visited);
            if(res != -1.0) return res * edge.val;
        }
        return -1.0;
    }
}
```