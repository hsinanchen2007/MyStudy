### 解题思路

第一步：对二叉搜索树进行一次中序遍历，此时会得到一个有序的数组。
第二步：重建树，得到一个 AVL 平衡二叉搜索树
    1. 从数组的中间位置取一个数，得到树的根节点 root。
    2. 对数组的左边和右边递归执行上面的过程，得到根节点的左儿子和右儿子

### 代码

```javascript
var balanceBST = function(root) {
    // 中序遍历
    let nodeList = inOrder(root)
    if (nodeList.length < 3) return root
    // 递归的方式重建树
    return rebuild(nodeList, 0, nodeList.length - 1)
};

function rebuild(list, left, right) {
    if (left > right) return null
    let mid = parseInt(left + (right - left) / 2)
    let root = list[mid]
    root.left = rebuild(list, left, mid-1)
    root.right = rebuild(list, mid+1,right)
    return root                  
}

function inOrder(root) {
    if (!root) return []
    let res = []
    let stack = []
    while(stack.length || root) {
        if (root) {
            stack.push(root)
            root = root.left
        } else {
            let node = stack.pop()
            res.push(node)
            root = node.right
        }
    }
    return res
}
```