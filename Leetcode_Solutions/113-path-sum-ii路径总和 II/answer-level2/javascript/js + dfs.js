
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    let result = [],list = [];
    if(!root){
        return [];
    }

    let one = (list,temp,root) => {
        if(!root){
            return;
        }

        temp += root.val;
        list.push(root.val);
        if(!root.left && !root.right && temp == sum){
            result.push(list);
            console.log(result)
            return;
        }
        console.log(list,temp)
        one(list.slice(0),temp,root.left);
        one(list.slice(0),temp,root.right);
    }

    one(list,0,root);
    return result;
};
```
