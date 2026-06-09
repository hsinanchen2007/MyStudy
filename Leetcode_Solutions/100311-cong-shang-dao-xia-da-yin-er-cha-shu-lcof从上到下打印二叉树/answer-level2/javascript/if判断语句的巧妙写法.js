### 自己略显冗余的代码
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
 * @return {number[]}
 */
// 按照同一层从左到右的顺序打印，因此使用广度优先遍历，先将同一层的遍历完，再遍历下一层的
// 要实现树的广度优先遍历策略，需要借助队列先进先出的特点，不然每次都还是会做成深度优先，树的左右节点性质就决定了每次会先遍历左节点
var levelOrder = function(root) {
    let res = [];
    
    if(!root) {
        return res;
    }
    // 初始化队列
    let queue = [root]
    // 跳出条件，队列为空，即所有节点都遍历完成
    while(queue.length) {
        // 拿出队首节点
        let node = queue.shift();
        res.push(node.val);
        if(node.left) {
            queue.push(node.left)
        }
        if(node.right) {
            queue.push(node.right)
        }
    }
    return res
};

```
### 大佬非常巧妙的用法
```
var levelOrder = function(root) {
    if (!root) {
        return [];
    }

    const data = [];
    const queue = [root];
    while (queue.length) {
        const first = queue.shift();
        data.push(first.val);
        // 这个判断条件太巧妙
        first.left && queue.push(first.left);
        first.right && queue.push(first.right);
    }

    return data;
};
```
