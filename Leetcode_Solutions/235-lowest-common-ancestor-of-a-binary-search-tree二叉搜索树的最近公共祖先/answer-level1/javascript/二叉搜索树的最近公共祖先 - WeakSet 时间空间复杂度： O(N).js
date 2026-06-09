### 解题思路
做之前学习到的关于二叉搜索树（BST）的性质：
- 节点 N 左子树上的所有节点的值都小于等于节点 N 的值
- 节点 N 右子树上的所有节点的值都大于等于节点 N 的值
- 左子树和右子树也都是 BST 

`结合下面示意图观赏更加:`  

![二叉搜索树示意图](https://pic.leetcode-cn.com/d4ae198f46c063a84c91dc0488917f7d501d2ee352a398aec9d7e3f7ecd97fc2-image.png)  

- 思路
 - 先遍历找到其中一个节点，并用WeakSet存储遍历经历过的节点
 - 再遍历查找第二个节点，如果`set中存在这个点`，更新公共点，但不跳出遍历，因为这不一定是最近。接着遍历，直到已找到目标点
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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

var lowestCommonAncestor = function(root, p, q) {
    const pv = p.val;
    const qv = q.val;
    const pPath = new WeakSet();
    let target = null;
    let temp = root;
    while(temp) {
        pPath.add(temp);
        if (pv === temp.val) {
            break;
        }

        // 大于节点，则往右节点上去找；
        if (pv > temp.val) {
            temp = temp.right;
        // 小于节点，则往左节点上去找；
        } else {
            temp = temp.left;
        }
    }

    temp = root;
    while(temp) {
        // 一直往下找，并更新target，保证target是最近的公共祖先
        if (pPath.has(temp)) {
            target = temp;
        }
        if (qv === temp.val) {
            // console.log('has');
            break;
        }

        if (qv > temp.val) {
            temp = temp.right;
        } else {
            temp = temp.left;
        }
    }
    return target;
};
```