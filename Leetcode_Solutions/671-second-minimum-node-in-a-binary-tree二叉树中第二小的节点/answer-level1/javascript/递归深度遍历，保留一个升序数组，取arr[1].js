### 解题思路
代码有注释

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
 * @return {number}
 */
var findSecondMinimumValue = function(root, arr) {
    // 根节点为null时的判定
    if(!root) {
        return -1
    }
    // 根节点时，设置数组，
    if(!arr) {
        arr =  [root.val]
    } else {
        // 非根节点，调整数组
        if(!arr.includes(root.val)) {
            if(root.val < arr[0]) {
                arr[1] = arr[0]
                arr[0] = root.val
            } else if(arr[1] == undefined || arr[1] > root.val) {
                arr[1] = root.val
            }
        }
    }
    if(root.left && root.right) {
        findSecondMinimumValue(root.left, arr),
        findSecondMinimumValue(root.right, arr)
    }
    // 根节点时有意义
    console.log(arr)
    if(arr.length !== 2) {
        return -1
    } else {
        return arr[1]
    }
};
```