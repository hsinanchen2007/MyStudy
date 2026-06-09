
```
[[]]
```
测试时，执行代码是正确的，但是提交时一直报错
```
Node with value 2 doesn't exist in the original graph.
```
代码如下：
```
//解法1. visited 放在了外面
let visited = new Map();

var cloneGraph = function (node) {
    if (!node) {
        return node;
    }
    if (visited.has(node.val)) {
        return visited.get(node.val);
    }
    var newNode = new Node(node.val, []);
    visited.set(newNode.val, newNode);
    for (let i = 0; i < node.neighbors.length; i++) {
        if (visited.has(node.neighbors[i].val)) {
            newNode.neighbors.push(visited.get(node.neighbors[i].val));
        }
        else {
            var b = cloneGraph(node.neighbors[i]);
            newNode.neighbors.push(b);
        }
    }
    return newNode;
};
```
此时代码执行结果下面会提示
**注意：假如发现执行代码和提交解答结果不同的话，很有可能是因为您使用了 C 或者 C++ 的全局变量**

但是把```visited```挪到内部就能提交通过。
```
//将全局visited放在内部
// let visited = new Map();
var cloneGraph = function (node,visited) {
    if(!visited){
        visited = new Map();
    }
    if (!node) {
        return node;
    }
    if (visited.has(node.val)) {
        return visited.get(node.val);
    }
    var newNode = new Node(node.val, []);
    visited.set(newNode.val, newNode);
    for (let i = 0; i < node.neighbors.length; i++) {
        if (visited.has(node.neighbors[i].val)) {
            newNode.neighbors.push(visited.get(node.neighbors[i].val));
        }
        else {
            var b = cloneGraph(node.neighbors[i],visited);
            newNode.neighbors.push(b);
        }
    }
    return newNode;
};
```
这是为啥？
