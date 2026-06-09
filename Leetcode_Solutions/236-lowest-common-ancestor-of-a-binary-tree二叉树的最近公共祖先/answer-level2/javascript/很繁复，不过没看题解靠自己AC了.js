### 解题思路
![image.png](https://pic.leetcode-cn.com/c70de314c193f6bd331b2e804191054b938ca7a505babf12c4fcaf8af18f41db-image.png)

肯定绕弯路了。。。
1. 遍历，组建一个map，用来存放{键 = 节点值，值 = 父节点值}
2. 组建两个数组，存放p，q遍历map一路向上找到根节点的途径
3. 找到公共祖先
4. 根据公共祖先的值返回公共祖先节点


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
var lowestCommonAncestor = function (root, p, q) {
    let parMap = new Map(),
        nodeArr = [];

    parMap.set(root.val, null);
    const travel = root => {
        if (root) {
            nodeArr.push(root);
            if (root.left) parMap.set(root.left.val, root.val);
            if (root.right) parMap.set(root.right.val, root.val);
            travel(root.left);
            travel(root.right);
        }
    }

    travel(root);

    const findPar = (map, val) => {
        let parArr = [];
        parArr.push(val);
        while (map.has(val)) {
            parArr.push(map.get(val));
            val = map.get(val);
        }
        return parArr;
    }

    let pParArr = findPar(parMap, p.val),
        qParArr = findPar(parMap, q.val),
        commPar;

    loop: {
        for (let i = 0; i < pParArr.length; i++) {
            for (let j = 0; j < qParArr.length; j++) {
                if (pParArr[i] === qParArr[j]) {
                    commPar = pParArr[i];
                    break loop;
                }
            }
        }
    }

    for (let i = 0; i < nodeArr.length; i++) {
        if (nodeArr[i].val === commPar) return nodeArr[i];
    }
};
```