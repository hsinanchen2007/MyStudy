### 解题思路
一开始我想错了，以为这是一个规则的搜索二叉树，一股脑儿的就想着用Queue的BFS搜索，
然而当遇到[1,2,3,4,null,null,5]这个case时，发现其实题目的二叉树并不是，所以改成了用DFS深度优先搜索。
1. 用一个记录深度的变量layer，没进入下一层递归就加1
2. 使用 MAP<深度, [本深度的元素列表]> 来记录已经收集的深度的那些nodes
3. 如此递归直到所有节点都遍历完

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
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    if(!root)return []; //防止被leetcode坑
    function dfs(node, layer, res){
        if(!res.has(layer))res.set(layer, []); //如果没有当前深度的记录，加进去
        res.get(layer).push(node.val); //把但前深度的node信息加入列表

        const [l, r] = [node.left, node.right];
        if(l)dfs(l, layer+1, res); //左右分支遍历
        if(r)dfs(r, layer+1, res);
    }
    const map = new Map();
    dfs(root, 0, map);
    return [...map.values()].reverse(); //因为我是从顶端开始加入map的，所以根据题目要求要从底部开始排列，得把数组反转
};
```