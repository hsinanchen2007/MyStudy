### 解题思路
迭代法很费脑筋

两个坑：
1. 右子节点先进栈 再将根进栈 这样子pop时 才符合先进先出的规则
2. 代码进入了死循环 描述一下：
加入 现在根节点 原封不懂入栈了 那么 再等左子节点 遍历完成后 再出栈 是不是 和第一次 调用这个函数一样了？判断有没有左子节点 判断 有的话 怎么怎么样 陷入了无限循环

正确做法：新建一块内存 仅将这个root.val 存取来 入栈即OK 因为我们只是想要 这个节点的val 
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
var inorderTraversal = function(root) {
    // 迭代来一波
    let result = [];
    let stack = [];
    while(root !== null || stack.length > 0){
        if( root === null ){
            root = stack.pop();
        }else{
            if( root.left !== null ){
                // 注意这个操作 避免进入死循环 我new一个新的节点 存放 跟节点的值  确保它的左右子节点为null 不然 进入 死循环 即：栈每次碰到 "相对的" 的根节点时 会 检查左右子节点 进入"死循环"
                let temp = new TreeNode(root.val);
                stack.push(root.right, temp);
                root = root.left;
            }else{
                result.push(root.val);
                root = root.right;
            }
        }
        
    }
    return result;
};
```