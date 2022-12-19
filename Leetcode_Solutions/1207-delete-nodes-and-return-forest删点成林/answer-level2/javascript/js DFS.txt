深度遍历


```js

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function(root, to_delete) {
    const map = {}, result= []
    // 将需要删除的节点转换为hash map储存
    to_delete.forEach(val => { map[val] = true })
    
    // 参数：自身节点，自身节点的父节点，自己是否为父节点的左子树
    function dfs(node, father, isLeft){
        if(!node) return 
        let del = false // 自己是否会被删除
        if(!map[node.val]){
            // 自己无需删除，且父节点不存在(已被删除),自己就会被放入森林中
            if(!father){
                result.push(node)
            }
        }else{
            // 自己需要删除， 需要将父节点的指向自己的指针设为null
            del = true
            if(father){
                if(isLeft) father.left = null
                else father.right = null
            }
        }
        // 递归dfs
        dfs(node.left, del ? null : node, true)
        dfs(node.right, del ? null : node, false)
    }

    dfs(root, null, true)
    return result
};
```