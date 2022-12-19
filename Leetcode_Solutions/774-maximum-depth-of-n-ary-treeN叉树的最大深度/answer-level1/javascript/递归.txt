### 解题思路
此处撰写解题思路

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
 * @return {number}
 */
var maxDepth = function(root) {
  if(!root) return 0                // 如果没有节点, 直接返回0
  let num = 0                       // 记录深度
  if(root.children){
    root.children.forEach(item=>{   // 遍历有几个节点
      let max = maxDepth(item)      // 递归调用
      num = Math.max(max, num)      // 对比当前和之前得到的 深度, 保留大的
    })
  }
  return num + 1                    // 顶级节点算一个 得加1
};
```