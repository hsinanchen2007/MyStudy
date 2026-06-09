### 解题思路

- 中序遍历 ``二叉搜索树`` 并生成有序数组
- 利用双指针找出目标值

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
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function(root, k) {
    /**
     * @param {TreeNode} root
     * @return {void}
     */ 
    const helper = (root) => {
        if (!root) {
            return
        }
        helper(root.left)
        res.push(root.val)
        helper(root.right)
    }
    let res = []
    helper(root)
    let left = 0
    let right = res.length - 1
    // 利用双指针，从两头逼近目标值 k
    // 如果找到 res[left] + res[right] === k，直接返回 true
    // 否则如果遍历完还没有找到，则返回 false
    while (left < right) {
        let target = res[left] + res[right]
        if (target === k) {
            return true
        }
        if (target < k) {
            left++
        } else {
            right--
        }
    }
    return false
};
```