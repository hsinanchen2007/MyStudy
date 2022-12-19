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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    const routeP = [], routeQ = []
    
    // 寻找路径数组函数，将到某点的路径一直保存在数组中
    function findRoute(aim, route){
        let point = root
        while(point.val !== aim.val){
            route.push(point)
            point = aim.val < point.val ? point.left : point.right
        }
        route.push(aim)
    }
    findRoute(p, routeP)
    findRoute(q, routeQ)
    // 寻找最近公共祖先
    let i = 1
    while(true){
        if(routeP[i]!==routeQ[i]){
            break
        }
        i += 1
    }
    return routeP[i-1]
};
```