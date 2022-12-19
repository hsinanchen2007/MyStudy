```
/**
 * @param {UndirectedGraphNode} graph
 * @param {{}UndirectedGraphNode} map
 * @return {UndirectedGraphNode}
 */
var cloneGraph = function(graph, map = {}) {
    if (!graph) return graph;

    const v = new Node(graph.val, []);
    map[v.val] = v;

    for (let w of graph.neighbors) {
        if (map[w.val]) {
            v.neighbors.push(map[w.val]);
        } else {
            v.neighbors.push(cloneGraph(w, map));
        }
    }

    return v;
}
```