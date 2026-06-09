![image.png](https://pic.leetcode-cn.com/cc68721a503084ada6c2b803138eb205951ae13dafa88080d30a0995173682a2-image.png)

### 解题思路
解决树德遍历，最简单的方法就是递归；
而这里判断对称，思路和判断两颗树是否完全相等类似；
差异就在将同位置相等，变为交叉相等；即：
left.left == right.right 和 left.right == right.left
详细实现请看代码；
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
 * @return {boolean}
 */
// 递归判断；
var isSymmetric = function(root) {
    if (!root) {
        return true;
    }
    // 递归函数，左子树和右子树相等性判断；
    function leftIsSameToRight(left, right) {
        // 左右右一方为空，那就判断左右是否全为空
        if (left === null || right===null) {
            return left === null && right===null
        }
        // 如果当前两个节点值相等，则继续判断子树是否交叉相等；
        return left.val === right.val ?
            leftIsSameToRight(left.left, right.right) && leftIsSameToRight(left.right, right.left):
            false;
    }
    return leftIsSameToRight(root.left, root.right);
}
// 广度优先遍历；逐层判断；
// 判断规则就是： 每一层的队列是对称的；
// 有性能问题，会超出时间限制；
var isSymmetricBeyondTime = function(root) {
    if (!root) {
        return true;
    }
    const nodes = [root];
    let finish = true;
    let length = 2;
    function checkNode(nodes) {
        const length = nodes.length;
        let res = true;
        for(let i = 0; i < length / 2; i++) {
            const head = nodes[i];
            const tail = nodes[length - 1 -i];
            if ((head && head.val) !== (tail && tail.val)) {
                res =  false;
                break
            }
        }
        return res;
    }
    while(nodes.length) {
        const node = nodes.shift();
        if (node) {
            nodes.push(node.left);
            nodes.push(node.right);
            finish = false;
        } else {
            nodes.push(null, null);
        }
        if (nodes.length === length) {
            if (finish) {
                break;
            }
            if(checkNode(nodes)) {
                length = length * 2;
                finish = true;
                continue;
            }
            return false;
        }
    }
    return true;
};
```