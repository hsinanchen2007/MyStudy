### 解题思路
广度优先搜索，整体思路就是一层一层的处理，当前层处理完，把下一层的数据加入到待处理quene中
注意点：处理层的时候，用的是循环上次进入的size，然后在处理每一个node的时候，将left和right添加到数组中，
这时候由于遍历的是上一层的size，所以新加入的只会在下一次被处理。

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
    if(root==null || root ==[]) {return []}
    let dataArr = []
    let quene = []
    dataArr.push(root)
    while(dataArr.length){
        let size = dataArr.length
        let tempArr = new Array()
        for(let i =0 ;i < size ; i ++){
            let node = dataArr.shift();
            tempArr.push(node.val)
            if(node.left){
                dataArr.push(node.left)
            }
            if(node.right){
                dataArr.push(node.right)
            }
        }
        quene.push(tempArr)

    }
    return quene
};
```