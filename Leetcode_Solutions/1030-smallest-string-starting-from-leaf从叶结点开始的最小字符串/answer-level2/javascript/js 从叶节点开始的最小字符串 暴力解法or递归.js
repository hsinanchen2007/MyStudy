![image.png](https://pic.leetcode-cn.com/228e5f33666681d7b14e7a9a7e22a9020bd200931e000a905c234800fd00c692-image.png)
1. 暴力解法，找出所有从叶节点开始的字符串，比较找出最小的

```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
var smallestFromLeaf = function(root) {
    if (root === null) return ''
    let list = []
    let fn = (root, arr) => {
        if (root === null) return
        arr.unshift(String.fromCharCode(root.val + 65).toLowerCase())
        if (root.left === null && root.right === null) {
            list.push(arr.slice().join(''))
            // return
        }
        if (root.left) {
            fn(root.left, arr)
        }
        if (root.right) {
            fn(root.right, arr)
        }
        arr.shift()
        return root
    }
    fn(root, [])
    let str = list[0]
    let len = list.length
    for(let i = 1; i < len; i++) {
        if (list[i].localeCompare(str) < 0) {
            str = list[i]
        }
    }
    return str
};
```

![屏幕快照 2020-01-17 下午2.11.52.png](https://pic.leetcode-cn.com/b47bca00fb164ba5ffe0f0df46bbebc9601f9f20e559b5c3433d6d3449e32061-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-17%20%E4%B8%8B%E5%8D%882.11.52.png)

2. 递归 递归找出从叶子节点开始的字符串，定一个flag字符串，localeCompare 方法比较当前字符串与flag大小，若当前字符串小于flag，则更新flag.

[And the way to convert number to character using js](https://stackoverflow.com/questions/48352137/how-to-convert-number-to-character-using-javascript) 

```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
var smallestFromLeaf = function(root) {
    let arr = [], flag = false
    let fn = (root, str) => {
        if (root === null) return ''
        let newStr = String.fromCharCode(root.val + 65).toLowerCase() + str
        if (root.left === null && root.right === null) {
            if (flag === false || newStr.localeCompare(flag) < 0) {
                flag = newStr
            }
        }
        fn(root.left, newStr)
        fn(root.right, newStr)
    }
    fn(root, '')
    return flag
};
```
