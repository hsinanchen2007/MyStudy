### 解题思路
思路清晰，叫我第一☝️（bfs专题）
三个关键点

- 记录每层个数 `len`
- 出队列时判断 `len === 0` 本层是否清空
- 复制时注意浅拷贝一下，因为 `临时数组 path` 要复用

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
 * @return {number[][]}
 */
// bfs
let arr
var levelOrder = function(root) {
    arr = []
    bfs(root)
    return arr
};
function bfs(root){
    if(!root) return
    let stack = [root],
        len = 1,  // 用于记录每层多少个node
        path = [] //临时数组
    
    while(stack.length !== 0){
        let node = stack.shift()
        len--

        path.push(node.val)
        // 如果不是null添加
        node.left && stack.push(node.left)
        node.right && stack.push(node.right)
        
        if(len === 0){
            // 本层结束了
            arr.push([...path])
            path = []
            len = stack.length
        }
    }
}
```