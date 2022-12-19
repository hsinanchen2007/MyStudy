## 第一版，循环 + 递归
> 88ms,35.6M。
```javascript []
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
var isSymmetric = function(root) {
  return root ? checkNode(root.left, root.right) : true;
};

function checkNode(left, right) {
  while (left || right) {
    // 在这里打印日志观察访问顺序和镜像对应位置的值
    // console.log(left && left.val, right && right.val);
    if (!left || !right) return false;
    if (!checkNode(left.right, right.left)) return false;
    if (left.val !== right.val) return false;
    left = left.left;
    right = right.right;
  }
  return true;
}
```
## 思路：设左子树A，右子树为B。A向左循环 同时 B向右循环，每次循环在A和B的对应位置检查是否符合对称。每次循环中访问到的A子代的左子树向右递归，同时B子代的所有右子树向左递归，检查对应位置的值是否符合对称
![未命名文件.jpg](https://pic.leetcode-cn.com/3a88c6a84bbe8c4099e3528774c3819eb2d46029f1d5bdfb953fe5131bf737ac-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.jpg)
