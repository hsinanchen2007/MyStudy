### 解题思路
深度优先

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
var sumEvenGrandparent = function(root) {
    let sum=0
    function helper(root,arr){
        if(!root) return
        arr.push(root.val)
        let pp=arr[arr.length-3]
        if(arr.length>2&&pp%2===0){
            sum+=root.val
        }
        helper(root.left,arr)
        helper(root.right,arr)
        arr.pop()
    }
    helper(root,[])
    return sum
};
```