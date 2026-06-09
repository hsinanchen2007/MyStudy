### 解题思路
执行用时 : 76 ms, 在所有 JavaScript 提交中击败了36.00%的用户
内存消耗 :35.1 MB, 在所有 JavaScript 提交中击败了100.00%的用户

看了题解发现思路和官方题解一致。。。官方题解果然是提供了一套新手专用解法么。。。

首先，由于题目中给出的是 
给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币 
因此题目必定有解，所以直接使用dfs进行深搜。

由于每个结点上需要存在的金币数量应该为当前节点的子节点数量 +1 ，因此每个节点需要移动的金币数量为 `node.val - node.left - node.right -1 `

且由于金币每经过一个节点就算作一次移动，因此只需要计算出当前节点的金币数和应有的金币数之差即为，当前节点达成金币移动所需要的移动步数。

需要注意的是，由于节点金币树可能小于子节点数量，因此需要对移动步数取绝对值，保证结果正确

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
var distributeCoins = function(root) {
    var ret = 0;
    
    var dfs = function (node){
    if(node == null) return 0;
    let l = dfs(node.left);
    let r = dfs(node.right);
    ret += Math.abs(l) + Math.abs(r);
    return node.val + l + r - 1;
    }
    
    dfs(root);
    return ret
};



```