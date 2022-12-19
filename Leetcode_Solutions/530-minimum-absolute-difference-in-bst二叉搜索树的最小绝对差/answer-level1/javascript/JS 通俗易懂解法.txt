### 解题思路
此处撰写解题思路
我是个小渣渣，记录一下js解法

二叉搜索树：根节点的值大于其左子树中任意一个节点的值，小于其右节点中任意一节点的值，这一规则适用于二叉查找树中的每一个节点
![20190502235601654.png](https://pic.leetcode-cn.com/29a76ee0b5b946cb49f2498eb88b4398d240f20718c1982e8d601cfd1b611104-20190502235601654.png)

1.因为是搜索二叉树，所以中序遍历出来的是升序

2.因为是已排序的数组，所以一次for循环，俩俩比对，记录下最小数就行了


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
 * @return {number}
 */
var getMinimumDifference = function(root) {
    let arr = []
    bst(root,arr)
    let min
    for(let i = 0; i < arr.length-1;i++){
        if(min){
            if(Math.abs(arr[i+1] - arr[i]) < min) min = Math.abs(arr[i+1] - arr[i])
        }else{
            min = Math.abs(arr[i+1] - arr[i])
        }
    }
    return min
};
var bst = function(root,val){
    if(root){
        bst(root.left,val)
        val.push(root.val)
        bst(root.right,val)
    }
}
```