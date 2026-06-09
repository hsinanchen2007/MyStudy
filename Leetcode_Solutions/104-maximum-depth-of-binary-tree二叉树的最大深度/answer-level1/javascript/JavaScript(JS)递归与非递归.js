![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

### 解题思路
DFS 思想，改改又能用

### 代码
递归代码一行解决

```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
    return root ? Math.max(maxDepth(root.left), maxDepth(root.right)) + 1 : 0
};
```
非递归笨方法
```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
    if (!root) return 0
    let queue = [root];
    let deep = 1;
    while (queue.length) {
        let arr = [];
        let len = queue.length;
        for (let i = 0; i < len; i++) {
            let curNode = queue.shift();
            if (curNode.left || curNode.right) {
                curNode.left && arr.push(curNode.left);
                curNode.right && arr.push(curNode.right);
            }
        }
        if(arr.length) {
            deep++;
            queue = queue.concat(arr);
        }
    }
    return deep
};
```