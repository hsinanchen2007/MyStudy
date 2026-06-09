1. 迭代 + Map记录节点所在层数和父节点的值
```js
/**
 * @param {TreeNode} root
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    let q = [root, null]
    let num = 0
    let resMap = {}
    while(q.length){
        let current = q.shift()
        if(!current){
            num++
            if(q.length) q.push(null)
        }else{
            if(resMap[x] && resMap[y]) break // 如果已经拿到目标值了，就可以跳出while循环了
            if(current.left) {
                current.left.parent = current.val
                q.push(current.left)
            }
            if(current.right) {
                current.right.parent = current.val
                q.push(current.right)
            }
            resMap[current.val] = [num, current.parent] // [层数， 父节点的值]
        }
    }
    return resMap[x][0] === resMap[y][0] && resMap[x][1] !== resMap[y][1]
};
```
```
执行结果：通过
执行用时 :76 ms, 在所有 JavaScript 提交中击败了23.76%的用户
内存消耗 :34.9 MB, 在所有 JavaScript 提交中击败了72.22%的用户
```

2. 递归 + Map记录节点所在层数和父节点的值
```js
/**
 * @param {TreeNode} root
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    let resMap = {}
    function fn(node, num = 0, parent = null){
        if(!node) return
        if(resMap[x] && resMap[y]) return
        resMap[node.val] = [num, parent]
        fn(node.left, num+1, node.val)
        fn(node.right, num+1, node.val)
    }
    fn(root)
    return resMap[x][0] === resMap[y][0] && resMap[x][1] !== resMap[y][1]
};
```
```
执行结果：通过
执行用时 :60 ms, 在所有 JavaScript 提交中击败了96.04%的用户
内存消耗 :34.9 MB, 在所有 JavaScript 提交中击败了72.22%的用户
```