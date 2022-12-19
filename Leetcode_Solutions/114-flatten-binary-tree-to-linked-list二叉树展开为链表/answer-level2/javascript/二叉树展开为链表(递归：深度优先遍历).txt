![image.png](https://pic.leetcode-cn.com/b3d43916f3abde1e7baffe7a04dc191ebbf32b4add59442e07536380860c07e1-image.png)

### 解题思路
如果这个题目没有原地二字，熟悉深度优先遍历的，这个题的难度肯定不会是中等，而是简单。难就难在原地，即不新增链表的情况下展开合并；

思路比较简单,中序遍历：
 - 先遍历节点本身，缓存右节点头；
 - 如果左节点存在，将左节点树挂载到右节点，同时将左节点置Null;
 - 递归遍历右节点；
 - 递归结束后，将最后一个节点的右节点指向缓存的右节点头；
 - 继续递归
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
    if (!root) {
        return null;
    }
    let temp = root;
    // 深度优先遍历
    function deepFisrt(next) {
        if(!next) { return; }
        // 缓存
        const rightTemp = next.right;
        temp.val = next.val;
        // console.log('val', next.val);
        // 左节点不为空，遍历
        if (next.left) {
            temp.right = next.left;
            temp = temp.right;
            next.left = null;
            deepFisrt(temp);
        }
        if (rightTemp) {
            temp.right = rightTemp;
            temp = temp.right;
            deepFisrt(temp);
        }
    }
    deepFisrt(root);
    // console.log(root);
};
```