### 解题思路
1. 如果有子节点的话，深度加1，然后遍历子节点；否则返回深度值
2. 重复1，递归检查下面的子节点
3. 重复遍历整棵树

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
    if(!root)return 0;
    let counter = 0;
    function deepthroat(node, depth){
        if(depth>counter)counter = depth; //如果最大深度超过记录的深度，更新记录的值
        if(node.children){
            depth++; //如果有子节点，深度加1
            for(let child of node.children){
                deepthroat(child, depth); //递归检查下面的子节点
            }
        }
    }
    deepthroat(root, 1, 0); //因为root本身就有一层了，所以初始化1，后面那个0是我之前尝试另一个做法时放进去忘记删了，请忽略
    return counter;
};
```