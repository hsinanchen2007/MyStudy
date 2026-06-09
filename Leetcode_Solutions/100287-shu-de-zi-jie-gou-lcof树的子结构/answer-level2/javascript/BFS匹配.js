### 解题思路
此处撰写解题思路

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
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function(A, B) {
    // 这是一个BFS
    let result = false;
    if(!A || !B) return result;
    let searchA = (node) => {
        if(result) return;
        if(!node) return;
        if(node.val == B.val) {
            BFS(node);
        }
        searchA(node.left);
        searchA(node.right);
    }
    let BFS = (node) => {
        let currentA = [node];
        let currentB = [B];
        let nextA = [];
        let nextB = [];
        let matchRes = true;
        while(currentB.length > 0 && matchRes) {
            if(currentA.length != currentB.length) {
                matchRes = false;
                break;
            }
            for(let i = 0; i < currentB.length; i++) {
                let At = currentA[i];
                let Bt = currentB[i];
                if(At.val != Bt.val) {
                    matchRes = false;
                    break;
                }
                if(Bt.left) {
                    if(!At.left) {
                        matchRes = false;
                        break;
                    }
                    nextA.push(At.left);
                    nextB.push(Bt.left);
                }
                if(Bt.right) {
                    if(!At.right) {
                        matchRes = false;
                        break;
                    }
                    nextA.push(At.right);
                    nextB.push(Bt.right);
                }
            }
            currentA = nextA;
            currentB = nextB;
            nextA = [];
            nextB = [];
        }
        if(matchRes) {
            result = true;
        }
    }
    searchA(A);

    return result;
};
```