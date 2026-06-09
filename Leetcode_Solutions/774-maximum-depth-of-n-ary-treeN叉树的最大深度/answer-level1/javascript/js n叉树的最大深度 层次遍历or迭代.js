1. 层次遍历求深度
![image.png](https://pic.leetcode-cn.com/58f6e3b3a941ff477829f8a56fca0f99fe80be5e6398f7685c9f7d6c6b4277ea-image.png)


```
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (root === null) return 0
    let quene = [root], count = 0
    while(quene.length) {  
        let list = []
        while(quene.length) {
            let root = quene.pop()
            if (root === null) break
            let child = root.children
            if (child) {
                for(let i = 0; i < child.length; i++) {
                    list.push(child[i])
                }
            }
        }
        quene = list
        count++
    }
    return count
};
```

2. 迭代
![image.png](https://pic.leetcode-cn.com/0b993de62a3654bf8cbafd496ceb7e2575a0c261fc985113c4532b09d7a3db12-image.png)


```
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number}
 */
var maxDepth = function(root) {
    let arr = []
    if (root === null) {
        return 0
    } else if (root.children === null) {
        return 1
    } else {
        let len = root.children.length
        for(let i = 0; i < len; i++) {
            arr.push(maxDepth(root.children[i]))
        }
    }
    return arr.sort((i, j) => i - j).slice(-1) * 1 + 1
};
```
