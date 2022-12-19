![FZ99EA7JMGUTPF@(}MJJAQ8.png](https://pic.leetcode-cn.com/18af71d461266a9b4c9e31667294e34655b4b0de44d8a21a428d4ab1f1efddb7-FZ99EA7JMGUTPF@\(%7DMJJAQ8.png)

### 解题思路
通过前序数组找到root，通过中序数组递归拆分左右子树。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    let map = new Map()
    let len = preorder.length

    // map保存中序数组的值和下标方便找到子树root的位置方便拆分
    inorder.forEach((val, index) => {
        map.set(val, index)
    })

    // 设置index为preorder的下标，代表当前子树的root
    let index = 0
    
    var fn = function (arr) {
        if (arr[0] > arr[1] || index >= len) return null

        // 通过index找到preorder中当前子树的root并创建node
        let rootVal = preorder[index]
        let node = new TreeNode(rootVal)

        // 每次递归一次代表有一个节点被使用了，index++就表示找到下一个使用的root
        index++
        // 从map中找到root的位置并根据位置拆分为left和right子树
        node.left = fn([arr[0], map.get(rootVal) - 1])
        node.right = fn([map.get(rootVal) + 1, arr[1]])

        return node
    }

    return fn([0, len - 1])
};
```