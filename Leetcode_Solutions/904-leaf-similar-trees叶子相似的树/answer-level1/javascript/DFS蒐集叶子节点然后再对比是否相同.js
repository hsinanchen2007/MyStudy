### 解题思路
1. 先蒐集所有叶子，也就是木有后代的节点，把它们统一放进一个数组
2. 得到数组1 和 数组2， 先对比数组的长度 然后再逐个位置对比数组里边的元素

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
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    function allLeaves(node, collected){
        const [lnode, rnode] = [node.left, node.right]; //得到当前节点的后代节点
        if(!lnode && !rnode){
            collected.push(node.val); //如果没后代的话，说明是叶子，收起来
        }else{
            if(lnode)allLeaves(lnode, collected); //否则再继续递归蒐索子结点
            if(rnode)allLeaves(rnode, collected);
        }
    }
    //对比结果是否相同
    function diff(arr1, arr2){
        if(arr1.length != arr2.length)return false;
        for(let index in arr1){
            if(arr2[index] !=arr1[index])return false;
        }
        return true;
    }

    const leaves1 = [], leaves2 = [];
    allLeaves(root1, leaves1);
    allLeaves(root2, leaves2);
    return diff(leaves1, leaves2);
};
```