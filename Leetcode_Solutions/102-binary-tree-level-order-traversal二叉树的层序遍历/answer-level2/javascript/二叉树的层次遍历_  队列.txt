### 解题思路

其实这道题应该是：广度优先遍历的一个变形；

而广度优先遍历的实现，就是用队列的思想实现；

但由于他这要求逐层，从左到右访问所有节点。。。所以一个队列是干不成的吗，得两个

被遍历取值的是父队列，被添加到新的遍历队列是子队列；当父队列遍历完成，子队列成对下一个父队列，子队列清空，迎接下一轮
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
var levelOrder = function(root) {
    if (!root) {
        return [];
    }
    let flag = 1;
    let queue = [root];
    const res = [];
    while(queue.length) {
        // 将待遍历队列提取出来
        const vals = queue;
        // 声明一个新的队列
        queue = [];
        let temp = [];
        while(vals.length) {
            const val = vals.shift();
            temp.push(val.val);
            // 形成新的带遍历队列
            val.left && queue.push(val.left);
            val.right && queue.push(val.right);
        }
        // 添加到结果；
        res.push(temp);
    }; 
    return res;
};
```