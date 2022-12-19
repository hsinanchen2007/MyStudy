执行用时 : 128 ms, 在Lowest Common Ancestor of a Binary Search Tree的JavaScript提交中击败了98.48% 的用户<br>

如果树节点的值位于p和q两节点值中间或与某个节点相等，则该节点一定是两节点最近父节点
否则如果树节点值大于两节点值，则两节点都位于树节点的左子树，将其左节点作为当前节点进行搜索
同理如果树节点值小于两节点值，则两节点都位于树节点的右子树，将其右节点作为当前节点进行搜索
```
let lowestCommonAncestor = function(root, p, q) {
    let temp = root;
    if(p.val > q.val) {
        [p, q] = [q, p];
    }
    while(true) {
        if((temp.val > p.val && temp.val <= q.val) || (temp === p || temp === q)) {
            return temp;
        } else if(temp.val < p.val && temp.val < q.val) {
            temp = temp.right;
        } else {
            temp = temp.left;
        }
    }
};
```