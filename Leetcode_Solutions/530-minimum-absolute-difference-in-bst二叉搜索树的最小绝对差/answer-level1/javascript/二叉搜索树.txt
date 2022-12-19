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
 * @return {number}
 */
var getMinimumDifference = function(root) {
    function recursion(node){
        if(node===null)return;
        recursion(node.left);
        if(last!==null){
            minValue=Math.min(minValue,node.val-last);
        }
        last = node.val;
        recursion(node.right);
    }

    var minValue=Infinity;
    var last=null;
    recursion(root);
    return minValue;
};
```
```
var getMinimumDifference = function(root) {
//BST 左节点的值<根节点<右节点
    var arr=[];
    push(root,arr);
    var minValue=Infinity;
//求数组中相邻两个元素差的最小值
    for(var i=0;i<arr.length-1;i++){
        if(arr[i+1]-arr[i]<minValue){
            minValue=arr[i+1]-arr[i];
        }
    }
    return minValue;

//中序遍历，存入数组
    function push(root,array){
        if(root!==null){
            push(root.left,array);
            array.push(root.val);
            push(root.right,array);
        }
        return array;
    }
};
```
