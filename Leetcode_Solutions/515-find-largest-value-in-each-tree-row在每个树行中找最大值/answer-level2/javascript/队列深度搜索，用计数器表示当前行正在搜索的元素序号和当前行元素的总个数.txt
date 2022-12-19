![image.png](https://pic.leetcode-cn.com/3e160f55313de5ef196df44d2067e5c09542bd0718c73abf0fd5100571ed9586-image.png)

### 解题思路
第一时间，想到了考研复习书上的广度优先搜索，用2个数，表示当前行正在索引的序号，和当前行的总节点个数
后来看了题解，还有更好的思路，（1）queue中节点直接加入深度信息  （2）不断改变queue，使queue中元素仅包含下一行元素
我的代码仅供参考

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
 * @return {number[]}
 */
var largestValues = function(root) {
    if(!root) return []
    let result = []
    let queue = []
    queue.push(root)
    let curLineIndex = 0, curLineTotal= 1 ,nextLineTotal = 0
    while(queue.length){
        let max_of_line = -Infinity
        while(curLineIndex < curLineTotal){
            let node = queue.shift()
            max_of_line = Math.max(max_of_line, node.val)
            if(node.left !== null) {
                queue.push(node.left) 
                nextLineTotal++
            }
            if(node.right !== null) {   
                queue.push(node.right)
                nextLineTotal++
            }
            curLineIndex++
        }
        result.push(max_of_line)
        curLineIndex = 0
        curLineTotal = nextLineTotal
        nextLineTotal = 0
    }
    return result
};
```