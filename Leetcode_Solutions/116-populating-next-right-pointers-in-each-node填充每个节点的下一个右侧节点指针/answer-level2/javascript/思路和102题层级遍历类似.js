### 解题思路
![image.png](https://pic.leetcode-cn.com/2489462a745dcb610bf165233d966a5e2831f3b41e08f7da995f70745d0a4528-image.png)

利用一个队列，1个出来，2个进去，next钩子连上；2个出来，4个进去，next钩子再连上。。。。

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */
/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function (root) {
    if (!root) return root;
    
    let curr = new Node();
        que = [root],
        len = 0;

    while (que.length != 0) {
        len = que.length;
        
        for (let i = 0; i < len; i++) {
            curr = que.shift();
            if (curr.left) que.push(curr.left);
            if (curr.right) que.push(curr.right);
        }
        que.forEach(function next(node,idx,arr){
            if(arr[idx+1]) node.next = arr[idx+1];
        })
    }

    return root;
}
```