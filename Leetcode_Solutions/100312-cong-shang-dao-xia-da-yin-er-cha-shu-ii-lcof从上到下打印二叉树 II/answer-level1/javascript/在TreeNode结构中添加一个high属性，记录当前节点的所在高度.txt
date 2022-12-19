### 解题思路
在TreeNode结构中添加一个high属性，记录当前节点的才能高度，便可轻松解决
![图片.png](https://pic.leetcode-cn.com/9c753027e641b81f43cf50a4873c5ede7141ade571d67ac80387d15240b7ec9d-%E5%9B%BE%E7%89%87.png)

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
function TreeNode(val) {
    this.val = val;
    this.high = 0;
    this.left = this.right = null;
}
var levelOrder = function(root) {
    let res=[];
    if(root===null)return [];
    let qu=[root];
    root.high=0;
    while(qu.length>0){
        let cur=qu.shift();
        if(res[cur.high]==undefined)res[cur.high]=[];
        res[cur.high].push(cur.val);
        if(cur.left){
            cur.left.high=cur.high+1;
            qu.push(cur.left);
        }
        if(cur.right){
            cur.right.high=cur.high+1;
            qu.push(cur.right);
        }
    }
    return res;

};
```