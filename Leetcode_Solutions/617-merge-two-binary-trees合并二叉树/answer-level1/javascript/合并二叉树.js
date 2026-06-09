### 解题思路
**方法一：递归**
对两颗树同时进行前序遍历，并将对应节点进行合并。
在遍历时，如果两颗树的当前节点均不为空，将它们的值进行相加，并对它们的左右孩子进行递归合并；如果其中有为空的返回另一颗树。
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
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function(t1, t2) {
     //如果两方树有一个为null，直接返回另一个树
    if(t1 == null){
        return t2;
    }else if(t2 == null){
        return t1;
    }else{
        let t = new TreeNode(t1.val + t2.val);
        t.left = mergeTrees(t1.left + t2.left);
        t.right = mergeTrees(t1.right + t2.right);
        return t;
    }
};
```

**方法二：迭代**
首先判断两棵树是否为空，其中之一为空则可直接返回；
如果均存在，首先把两棵树存在栈中，之后根据栈是否为空进行判断循环。
如果当前出栈节点之一为空，跳出当前循环，继续执行循环判断，否则将当前两节点的值相加，并对左右孩子进行判断处理。
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
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function(t1, t2) {
     //如果两方树有一个为null，直接返回另一个树
    if(t1 == null){
        return t2;
    }else if(t2 == null){
        return t1;
    }else{
        let stack = [];
        stack.push([t1,t2]);
        while (stack.length) {
            t = stack.pop();
            if(t[0] == null || t[1] == null)
                continue;
            t[0].val += t[1].val;
            if (t[0].left == null) {
                t[0].left = t[1].left;
            } else {
                stack.push([t[0].left, t[1].left]);
            }
            if (t[0].right == null) {
                t[0].right = t[1].right;
            } else {
                stack.push([t[0].right, t[1].right]);
            }
        }
        return t1;
    }
};
```