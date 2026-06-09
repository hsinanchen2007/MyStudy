```javascript []
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
    const result = []
    const digui = function(node, route, localSum){
        if(!node) return
        route.push(node.val)
        if(!node.left && !node.right && node.val + localSum === sum){
            result.push(route.slice())
        }else{
            if(node.left) digui(node.left, route.slice(), localSum + node.val)
            if(node.right) digui(node.right, route.slice(), localSum + node.val)
        }
    }
    digui(root, [], 0)
    return result
};
```

