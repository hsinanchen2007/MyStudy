### 解题思路
此处撰写解题思路
写一个中序排列，然后克隆数组，对克隆数组进行排序
使用克隆数组建立一个set去重
再转换成基本类型String判断时候和中序排列数组相等
如果是一个bst，它的中序应该是递增的

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
 * @return {boolean}
 */
var isValidBST = function(root) {

    let arr = []
    let stack = []
    while(root || stack.length){
        if(root.left !== null){
            stack.push(root)
            root = root.left
        } else if( !root.left && !root.right){
            arr.push(root.val)
            root = stack.pop()
            root && (root.left = null)
        } else if(root.right !== null){
            arr.push(root.val)
            root = root.right
        }
    }


    let b = Object.create(arr)
    b.sort( (a,b) => a-b)

    let set = new Set(b)

    if(b.length !== set.size){
        return false
    } else {
        return arr.join('') === b.join('')
    }

};
```