### 解题思路
DP

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
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
    if(n == 0) return []
    let DP = new Array(n+1)
    DP[0] = [null]
    DP[1] = [new TreeNode(1)]
    
    if(n < 2) return DP[n]

    for(let i = 2; i <= n; i++) {
        DP[i] = []
        for(let j = 0; j < i; j++) {
            DP[j].forEach(ele => {
                DP[i - j - 1].forEach(ele2 => {
                    DP[i].push(getNewBTS(ele,ele2,j))
                })
            })
        }
    }
    return DP[n]
};
function getNewBTS(left, right, leftCount) {
    let newNode = new TreeNode(leftCount + 1)

    newNode.left = treeCopy(left)
    newNode.right = traversalAddTree(newNode.val, treeCopy(right))

    return newNode
}
function treeCopy(node) {
    if(node == null) return null
    let newNode = new TreeNode(node.val)

    newNode.left = treeCopy(node.left)
    newNode.right = treeCopy(node.right)

    return newNode
}
function traversalAddTree(val, node) {
    if(node == null) return null
    node.val = node.val + val
    traversalAddTree(val, node.left)
    traversalAddTree(val, node.right)
    return node
}
```