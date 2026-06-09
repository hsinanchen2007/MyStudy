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
  if (!root) return [];
  var result = [], // 结果集
  tmp = [root]; // 临时存储此层结点   以便后续依次取出
  while (tmp.length) {
    var childtmp = []; // 临时存储此层的所有子节点，一边下一次循环用做tmp来使用
    var level = []; // 把每一层的val放入一个数组中，以便每一层结束后拼接进入结果集result

    for (var i = 0, len = tmp.length; i < len; i++) {
      level.push(tmp[i].val); // 每一層的去收集
      // 有左右孩子时再去把左右孩子放进childtmp中
      if (tmp[i].left) 
      	childtmp.push(tmp[i].left);
      if (tmp[i].right)
      	childtmp.push(tmp[i].right);
    }
    tmp = childtmp;
    result.push(level);
  }
  return result;
};
```