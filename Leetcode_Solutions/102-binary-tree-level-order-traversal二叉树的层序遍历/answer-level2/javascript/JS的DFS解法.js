使用DFS中的中序遍历，增加一个层级的变量，由于闭包的特性，在每个函数调用中的层级都是自己当前的层级
```JS
var levelOrder = function (root) {
  const result = [];

  const traverse = (node, layer) => {
    if (node !== null) {
      traverse(node.left, layer + 1);
      result[layer] ? result[layer].push(node.val) : result[layer] = [node.val];
      traverse(node.right, layer + 1);
    }
  }
  traverse(root, 0);
  return result;
};
```