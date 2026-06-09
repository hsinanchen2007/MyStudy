### 解题思路
使用bfs遍历实现
![图片.png](https://pic.leetcode-cn.com/f3b17452e685a6c2daaa45ed5a59b5ebb9210ad15311311e92d23bf05a394ff0-%E5%9B%BE%E7%89%87.png)


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
var levelOrder = function(root) {
    if(root==null)return [];
    //bfs遍历即可
    let res=[];
    let qu=[root];
    while(qu.length>0){
        let p=qu.shift();
        res.push(p.val);
        if(p.left!==null)qu.push(p.left);
        if(p.right!==null)qu.push(p.right);
    }
    return res;



};
```