### 解题思路
和二叉树前序遍历方法一样。注意点：迭代法利用栈先进后出，需要反着遍历。

### 代码
**迭代**
```javascript
var preorder = function (root) {
    if (!root) return []
    let stack = [root];
    let arr = [];
    while (stack.length > 0) {
        let node = stack.pop();
        arr.push(node.val)
        if (node.children) {
            for (let i = node.children.length - 1; i >= 0; i--) {
                stack.push(node.children[i]);
            }
        }
    }
    return arr
};
```
**递归**

```javascript
var preorder = function (root) {
    if (!root) return []
    let arr = [];
    let recursion = function (node, arr) {
        if (!node) return arr
        arr.push(node.val);
        for (let i = 0; i < node.children.length; i++) {
            recursion(node.children[i], arr)
        }
    }
    recursion(root, arr);
    return arr
};
```
