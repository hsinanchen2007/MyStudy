### 解题思路
#### 该题就是要我们遍历树，再左右子树交换位置
  用递归很简单，，也可以用栈来代替递归  
  因为递归本质上就是函数执行栈
  下面是栈的解题


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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (!root) return root //判断非空树
    
    const stack = [root] //将跟节点入栈
    var current = null;
    while((current = stack.shift())) { //取出栈中第一个元素 用pop()也一样
        const left = current.left
        const right = current.right
        current.right = left;  //右指针指向左子树
        current.left = right;   //左指针指向右子树
        if (left) stack.push(left)  //左子树入栈
        if (right) stack.push(right) //右子树入栈
    }
    

  return root
};
```