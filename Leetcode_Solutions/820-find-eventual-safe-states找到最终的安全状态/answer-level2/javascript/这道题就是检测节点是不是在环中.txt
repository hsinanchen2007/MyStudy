```
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    const ans = []
    const color = new Array(graph.length).fill(0)
    for(let i = 0;i < graph.length;i++) {
        if(dfs(graph, color, i)) ans.push(i)
    }
    
    return ans
};

function dfs(graph, color, i) {
    if(color[i]) return color[i] === 2
    color[i] = 1
    for(node of graph[i]) {
        if((color[node] === 1) || !dfs(graph, color, node)) return false
    }
    color[i] = 2
    return true
}
```
