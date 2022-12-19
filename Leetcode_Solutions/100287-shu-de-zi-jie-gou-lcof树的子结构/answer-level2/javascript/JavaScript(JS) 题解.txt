### 解题思路
此处撰写解题思路

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
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function (A, B) {
    let result = false;
    if (A && B) {
        if (A.val === B.val) {
            // 结点相同，判断子结点
            result = AHasB(A, B);
        }
        if (!result) {
            result = isSubStructure(A.left, B);
        }
        if (!result) {
            result = isSubStructure(A.right, B);
        }
    }
    return result
};

/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
function AHasB(A, B) {
    // 遍历结束返回 true
    if (!B) {
        return true
    }
    // A遍历完而B还剩余，返回 false
    if (!A) {
        return false
    }
    // 结点值不等，返回 false
    if (A.val !== B.val) {
        return false
    }
    // 结点相等，继续判断左右子节点
    return AHasB(A.left, B.left) && AHasB(A.right, B.right)
}
```