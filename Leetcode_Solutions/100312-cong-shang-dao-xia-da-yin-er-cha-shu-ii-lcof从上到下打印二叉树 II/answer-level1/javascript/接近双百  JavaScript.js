### 解题思路
![image.png](https://pic.leetcode-cn.com/bd34fc52f0c8c31be72e2c1f6756b3b460acfd7ce307222d8c941d0c1b6f1a10-image.png)


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
    if(!root) return [];
    let res = [];
    let height = 0;
    let nowLayer = [root];//当前层
    while(true) {
        res[height] = [];
        let auxiliaryLayer = [];//辅助层
        while(nowLayer.length) {
            let temnode = nowLayer.shift();
            res[height].push(temnode.val);
            temnode.left && auxiliaryLayer.push(temnode.left);
            temnode.right && auxiliaryLayer.push(temnode.right);
        }
        height ++;
        if(auxiliaryLayer.length) {
            nowLayer = auxiliaryLayer;
        }else 
            return res;
    }
};
```