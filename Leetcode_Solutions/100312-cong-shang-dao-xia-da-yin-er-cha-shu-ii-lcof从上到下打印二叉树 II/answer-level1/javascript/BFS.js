### 解题思路
- 需要注意层次的遍历。
- 临时数组的位置和queue的长度

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
    const res =[]
    if(root==null){
        return res
    }
    const queue = [];
    queue.push(root)
    //因为是二维数组所以要用两层循环
    while(queue.length>0){
        //获取每层的长度
        let len = queue.length;
        //声明临时数组
        let tempArr = []
        /**
         * 例子：3，9，20，null,null,15,7
         * 当前queue长度是1
         * 当前的根值是3
         * 所以遍历一次
         * 判断左右树是否存在，如果存在，添加到queue数组中。
         */
        for(let i =0; i<len;i++){
            let nodes = queue.shift()
            tempArr.push(nodes.val);
            if(nodes.left){
                queue.push(nodes.left)
            }
            if(nodes.right){
                queue.push(nodes.right)
            }
        }
        res.push(tempArr);
    }
    return res
};
```