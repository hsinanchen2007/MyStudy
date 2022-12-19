### 解题思路
双栈存储
一个存奇数，一个存偶数
0当作偶数，如果是偶数，
先判断stack中是否为空，不为空则判断栈顶是否为null
若不为弹出栈顶，把左右子树分别存到奇数池中，
由于奇数池需要从右往左遍历，
故存的时候先存左节点其后右节点
奇数同理

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
var zigzagLevelOrder = function(root) {
    // 双栈存储
    let evenStatck = [],
        oddStack = [],
        res = []

    evenStatck.push(root)
    for(let  i = 0; evenStatck.length != 0 || oddStack.length != 0; i++) {
        let curList = []
        // 判断奇偶
        if((i & 1) == 0) {
            // 偶数
            while(evenStatck.length != 0) {
                let popTree = evenStatck.pop()
                if(popTree != null) {
                    curList.push(popTree.val)
                    // 往奇数池中加
                    oddStack.push(popTree.left)
                    oddStack.push(popTree.right)
                }
            }
        }else {
            while(oddStack.length != 0) {
                let popTree = oddStack.pop()
                if(popTree != null) {
                    curList.push(popTree.val)
                    evenStatck.push(popTree.right)
                    evenStatck.push(popTree.left)
                }
            }
        }
        if(curList.length != 0) {
            res.push(curList)
        }
    }
    // console.log(res)

    return res
};
```