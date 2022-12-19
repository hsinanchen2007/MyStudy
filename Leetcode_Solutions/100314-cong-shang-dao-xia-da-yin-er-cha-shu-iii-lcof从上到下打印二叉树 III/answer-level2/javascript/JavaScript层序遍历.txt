### 解题思路
此处撰写解题思路

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
    //BFS，层序遍历二叉树
    if (!root) return [];
    let queue = [root], res = [], state = 0; //state为偶数时从左到右
    while(queue.length){
        const levelNum = queue.length;
        const curLevel = [];
        for(let i = 0; i < levelNum; i++){
            const cur = queue.shift();
            cur.left && queue.push(cur.left);
            cur.right && queue.push(cur.right);
            curLevel.push(cur.val);
        }
        
        // 只需要在最后输出每一行的时候反转输出即可
        if(state%2===0) { 
            res.push(curLevel);
            state++;
        }else{
            res.push(curLevel.reverse());
            state++;
        }  
    }
    return res;
};
```