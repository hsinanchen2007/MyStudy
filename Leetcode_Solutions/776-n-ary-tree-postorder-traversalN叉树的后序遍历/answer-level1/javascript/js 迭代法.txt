![image.png](https://pic.leetcode-cn.com/2dfb2490f1249fdf31bf83a013013c45f7467073473f32dfb7f8a47a1033f71f-image.png)


### 解题思路
```js
迭代法：
后续遍历顺序：左 - 右 - 根
多叉树的话也是孩子从左到右，然后根的顺序

所以用栈处理的话，入栈就要从后向左，逆序入栈，取栈顶元素的时候，就是从左到右的顺序了
注意一点就可以：当栈顶元素的还有 children 的话，那么不能取出它（因为后序遍历是最后再遍历根），要先把它的孩子节点
入栈，并把这个点的孩子设置为空
遇到没有孩子的节点，就取出它，并添加到结果数组中
```

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */

var postorder = function(root) {
  let ans = [], stack = [root];
  
  while (stack.length > 0) {
    let top = stack[stack.length - 1],
        topIndex = stack.length - 1;
    
    if (top === null) {
      stack.pop();
      continue;
    }
    
    if (top.children !== null) {
      for (let i = top.children.length - 1; i >= 0; i--) {
        stack.push( top.children[i] );
      }
      
      stack[topIndex].children = null;
    } else {
      ans.push( top.val );
      stack.pop();
    }
  }
  
  return ans;
};
```