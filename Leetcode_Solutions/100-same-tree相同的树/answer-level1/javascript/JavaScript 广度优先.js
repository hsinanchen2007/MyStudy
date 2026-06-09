```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 * 树的遍历 广度优先
 */
var isSameTree = function(p, q) {
    if(!p && !q) {
        return true;
    }
    let pQueue = [p], qQueue = [q];
    let res = true;
    while(true) {
        if (!pQueue.length || !qQueue.length) {
            res = pQueue.length === qQueue.length;
            break;
        }
        let currentP = pQueue.shift();
        let currentQ = qQueue.shift();
        let isValid = true;
        if(
            (!currentP && currentQ) ||
            (currentP && !currentQ) ||
            (currentP && currentQ && currentP.val !== currentQ.val)
        ) {
            isValid = false;
        }
        if (isValid) {
            let pLeft = currentP ? currentP.left : null,
                pRight = currentP ? currentP.right : null;
            if (pLeft || pRight) {
                pQueue.push(pLeft);
                pQueue.push(pRight);
            }
            let qLeft = currentQ ? currentQ.left : null,
                qRight = currentQ ? currentQ.right : null;
            if (qLeft || qRight) {
                qQueue.push(qLeft);
                qQueue.push(qRight);
            }
        } else {
            res = false;
            break;
        }
    };
    return res;
};
```