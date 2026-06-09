### 解题思路
练习广度优先 思考如何实现 也是看了别人的代码 引起的思路 学习ing
写一下容易进的坑吧：
1. while循环里边 left === null && right === null 判断完之后 要 continue 而不是 直接return true 因为可能栈里边还有 没有进行比较的
2. 最外层要写一个return true 因为所有的return false 的情况 在while循环里边已经 列出了 最后的return true 最外层要兜底
3. stack.push 时 注意顺序 一定要注意顺序 我就在这里栽坑了 这道题要求的是对称二叉树 左.左子节点 要和 右.右子节点 比较 注意顺序
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
var isSymmetric = function(root) {
    // BFC
    // 栈
    if(root === null){
        return true;
    }
    let stack = [root, root];
    let left = null;
    let right = null;
    while(stack.length > 0){
        left = stack.shift();
        right = stack.shift();
        if( left === null && right === null ){
            // return true;
            continue;
        }else if(left === null || right === null){
            return false;
        }else if(left.val !== right.val){
            return false;
        }
        // 如果其中有一个是null 上面就判断完返回false了
        stack.push(left.left, right.right, left.right, right.left);
    }
    return true

};
```