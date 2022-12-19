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
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
  let stack = []  //  迭代算法用的栈
  let sum = 0   //  结果
  stack.push(root)
  while(stack.length > 0){
    root = stack.pop()
    if(!root){
      continue;
    }
    if(root.val >= L && root.val <=R){
      stack.push(root.left)
      stack.push(root.right)
      sum += root.val
    }else if(root.val < L){
      stack.push(root.right)
    }else{
      stack.push(root.left)
    }
  }
  return sum
};
```

递归算法 绝大部分 都可以通过 迭代算法（栈+while） 进行转换

1.先将root入栈
2.while条件直到栈空了，每次取出栈顶元素，如果是null 比如左节点不存在，直接continue跳出该次while
3.如果存在则判断节点大小，如果在L R之间，则说明左右两边都有可能还有符合条件的值 左右继续入栈 并加上值
4.如果 < L，则说明可能的值在右侧子树 右节点入栈，反之左节点入栈
