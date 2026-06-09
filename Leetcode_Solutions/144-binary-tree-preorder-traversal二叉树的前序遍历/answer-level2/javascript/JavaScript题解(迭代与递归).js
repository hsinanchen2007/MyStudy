### 解题思路
迭代与递归。函数入参是根节点root，返回值是遍历结果数组arr。

### 代码
迭代
```javascript
/**
 * 先序遍历：迭代方式
 * @param {TreeNode} root
 * @return {arr[]}
 */
var preorderTraversal = function (root) {
    let stack = [root]
    let arr = []
    while (stack.length > 0) {
        let node = stack.pop();
        node && arr.push(node.val); // node不为空时，向arr中推入节点值
        node && node.right && stack.push(node.right); // 模拟栈，所以先压右节点
        node && node.left && stack.push(node.left); // 后入先出，后压左节点
    }
    return arr
};
```

递归
```javascript
var preorderTraversal = function(root) {
    let arr = [];
    let preOrder = function(node, arr) {
        if(!node) return arr
        arr.push(node.val);
        node.left && preOrder(node.left,arr);
        node.right && preOrder(node.right,arr);
        return arr
    }
    preOrder(root,arr);
    return arr
};
```
