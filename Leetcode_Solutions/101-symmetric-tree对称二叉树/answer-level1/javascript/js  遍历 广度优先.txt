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
 * @return {boolean}
 * 队列 广度优先 queue 为每一层节点的数组，两两比较，注意的是节点压进 queue 的顺序
 */
var isSymmetric = function(root) {
    if(!root) {
        return true;
    }
    let queue = [root];
    let res = true;
    while(queue.length) {
        if (queue.length === 1) {
            let current = queue.shift();
            let leftVal = current.left ? current.left.val : null;
            let rightVal = current.right ? current.right.val : null;
            if (leftVal !== rightVal) {
                return false;
            } else if (leftVal && rightVal) {
                queue.push(current.left, current.right);
            }
        } else {
            let nextQueue = [];
            for(let i = 0; i < queue.length; i = i + 2) {
                let pLeft = queue[i].left;
                let pRight = queue[i].right;
                let qLeft = queue[i + 1].left;
                let qRight = queue[i + 1].right;
                if(
                    (pLeft && !qRight) ||
                    (!pLeft && qRight) ||
                    (pLeft && qRight && pLeft.val !== qRight.val)
                ) {
                    return false;
                } else {
                    pLeft ? nextQueue.push(pLeft) : null;
                    qRight ? nextQueue.push(qRight) : null;
                }
                if(
                    (pRight && !qLeft) ||
                    (!pRight && qLeft) ||
                    (pRight && qLeft && pRight.val !== qLeft.val)
                ) {
                    return false;
                } else {
                    pRight ? nextQueue.push(pRight) : null;
                    qLeft ? nextQueue.push(qLeft) : null;
                }
            }
            queue = nextQueue;
        }
    }
    return res;
};
```