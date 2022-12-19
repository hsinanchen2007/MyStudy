### 解题思路
![image.png](https://pic.leetcode-cn.com/871fd1f2490e1afbcfa9ada3104528467a43add27fa04af3a1c1288f2e7e36d6-image.png)


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
var connect = function(root) {
    if (!root) return root;
    
    let curr = new Node(),
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
};
```