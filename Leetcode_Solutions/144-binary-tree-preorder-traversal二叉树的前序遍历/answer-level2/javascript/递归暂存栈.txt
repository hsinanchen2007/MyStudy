### 解题思路

使用栈保存node
拿到一个节点，检查是否为null

 * 非null, 保存值，添加到暂存栈，指向它的left
 * null，则从栈里pop出来一个node，并且指向它的right
### 代码

```javascript
/**
 * 迭代的方法
 * 拿到一个节点，检查是否为null
 * 非null, 保存值，添加到暂存栈，指向它的left
 * null，则从栈里pop出来一个node，并且指向它的right
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function (root) {
    let result = [];

    //暂存
    let temp = [];

    //检查的node
    let node = root;

    while (node !== null || temp.length > 0) {

        if (node !== null) {
            result.push(node.val);
            temp.push(node);
            node = node.left;
        } else {
            node = temp.pop().right
        }
    }
    return result;
};
```