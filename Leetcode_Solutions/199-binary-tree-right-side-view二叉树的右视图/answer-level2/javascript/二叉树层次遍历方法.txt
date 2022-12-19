### 解题思路
1.首先要明白找到从右边看第一个节点，就是广度优先遍历的最后一个值
2.广度优先我们用层次遍历的方式来解
3.用一个队列来记录进队出队的顺序，每当一个节点已经将孩子节点都纪录到队列时，将该节点从队列中移除
4.size用于纪录当前层节点的数量，当所有节点的孩子都被纪录时，则可以开始遍历下一层的节点了
5.如果从右往左进队的话，那么一层的第一个节点就是从右边可以看到的值

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
var rightSideView = function(root) {
    if(!root) return []
    // 用于纪录最右边的节点
    let res = []
    //节点的队列
    let queue = [];
    queue.push(root);
    while(queue.length){
        //将该层的第一个节点放入结果队列中
        res.push(queue[0].val);
        //表示这一层的节点数量
        let size = queue.length;
        //遍历这一层的所有节点
        while(size--){
            //遍历到的当前节点，将它的孩子节点放入队列中（下一层），并将该节点出队
            let lastNode = queue.shift();
            //孩子节点从右往左依次进队
            if(lastNode.right) queue.push(lastNode.right);
            if(lastNode.left) queue.push(lastNode.left);
        }
    }
    return res;
};
```