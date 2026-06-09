![image.png](https://pic.leetcode-cn.com/8cc0dc9ff11e5ba7f02677b7d482da0faa62a8a8906efd8e92fceb1e86245934-image.png)
1. 递归
```
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
    if (root === null) return null
    if (root.left) {
        root.left.next = root.right
    }
    if (root.right && root.next !== null) {
        root.right.next = root.next.left
    }
    connect(root.left)
    connect(root.right)
    return root
};
```

![image.png](https://pic.leetcode-cn.com/d4fc6b239ff78795c5f20460a0596ad1ea91136a0f1169603980bc5ed5a23bb2-image.png)

2. 层次遍历
```
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
    let stack = [root], list = []
    while(stack.length) {
        let temp = [], pre = null
        let len = stack.length
        for(let i = 0; i < len; i++) {
            let root = stack.shift()
            if (root === null) break
            if (i > 0) {
                pre.next = root
            }
            pre = root
            if (root.left) {
                stack.push(root.left)
            }
            if (root.right) {
                stack.push(root.right)
            }
        }
    }
    return root
};
```

利用list保存每层元素，不符合额外常量空间的要求，故舍弃
```
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
    let stack = [root], list = []
    while(stack.length) {
        let temp = []
        while(stack.length) {
            let root = stack.shift()
            if (root === null) break
            list.push(root)
            if (root.left) {
                temp.push(root.left)
            }
            if (root.right) {
                temp.push(root.right)
            }
        }
        stack = temp
        let len = list.length
        for(let i = 0; i < len; i++) {
            if (i < len - 1) {
                list[i].next = list[i+1]
            } else {
                list[i].next = null
            }
        }
        list = []
    }
    return root
};
```
