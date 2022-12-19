### 解题思路
![image.png](https://pic.leetcode-cn.com/fd260daa6a40fc362a0c5725cf9d160aeedfff95e9b2aa05d77f983abae9e863-image.png)

感觉繁琐无比的套路，面试官说“你能再提供一个慢一点的算法吗”，我就想了这个方案给到他。。。。。
![image.png](https://pic.leetcode-cn.com/e9a52196d998cf68459f492bb023b14b9b7123bf2c3adb42ca40e1f6b15390ca-image.png)

好吧，就是对着左树走“中-左-右”，对着右树走“中-右-左”，但是不能跳过null啊，于是我搞了一个对象来放“外节点”和“内节点”（不用左右而用内外），但是对象always是不相等的啊，于是我又搞了个循环来深度遍历对象数组。

好吧，发完这个题解，我就去看高手的套路了……

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
var isSymmetric = function (root) {
    if (!root) return true;

    let treeArrL = [],
        treeArrR = [];

    let treeObj = function () {
        val = 0;
        hasOuter = true;
        hasInner = true;
    }

    const travel = (root, direction) => {
        let obj = new treeObj();
        if (root) {
            obj.val = root.val;
            if (direction === "L") {
                if (root.left) obj.hasOuter = true;
                if (root.right) obj.hasInner = true;
            } else if (direction === "R") {
                if (root.right) obj.hasOuter = true;
                if (root.left) obj.hasInner = true;
            }
        }

        if (direction === "L") {
            treeArrL.push(obj);
            if (root.left) travel(root.left, "L");
            if (root.right) travel(root.right, "L");

        } else if (direction === "R") {
            treeArrR.push(obj);
            if (root.right) travel(root.right, "R");
            if (root.left) travel(root.left, "R");
        }

    }

    if (root.left) travel(root.left, "L");
    if (root.right) travel(root.right, "R");

    if (treeArrL.length != treeArrR.length) {
        return false;
    } else {
        for (let i = 0; i < treeArrL.length; i++) {
            if (treeArrL[i].val === treeArrR[i].val && treeArrL[i].hasInner === treeArrR[i].hasInner && treeArrL[i].hasOuter === treeArrR[i].hasOuter) {
            } else {
                return false;
            }
        }
    }

    return true;

};
```