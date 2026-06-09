### 思路一

- 将前序遍历结果用 ``数组`` 存起来
- 遍历 ``数组``，将节点用 ``right`` 指针连接起来即可

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
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    const helper = (root) => {
        if (!root) {
            return
        }
        res.push(root)
        helper(root.left)
        helper(root.right)
    }
    let res = []
    helper(root)
    for (let i = 0; i < res.length; i++) {
        res[i].left = null
        res[i].right = res[i + 1]
    }
};
```


### 思路二

如果按先遍历 ``right`` 再遍历 ``left`` 生成的「后序遍历」，我们会发现这和 ``前序遍历`` 的结果刚好相反。利用这个特点，我们可以在 $O(1)$ 的空间复杂度内解决这道题。

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
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    const helper = (root) => {
        if (!root) {
            return
        }
        helper(root.right)
        helper(root.left)
        root.right = prev
        root.left = null
        prev = root
    }
    let prev = null
    helper(root)
};
```