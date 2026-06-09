### 解题思路
第k大的节点，显然就是逆中序遍历的第k个节点，即右->根->左的顺序遍历

### 代码

```javascript
var kthLargest = function(root, k) {
    // 二叉搜索树的逆中序遍历
    if (!root) return null;

    let stack = [], count = 0;

    while (root || stack.length) {
        if (root) {
            stack.push(root);
            root = root.right;
        } else {
            let cur = stack.pop();
            if (++count == k) {
                return cur.val;
            }
            root = cur.left;
        }
    }
    return null;
};
```