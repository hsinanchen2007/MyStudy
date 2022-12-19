```js
var kthLargest = function(root, k) {
    let res = []//从大到小排序的数组
    treeToSortedArr(root)//右中左递归
    return res[k-1]//返回k大的值
    //中序遍历 右中左
    function treeToSortedArr(root){
        if(!root ) return 
        treeToSortedArr(root.right,res)
        res.push(root.val)
        treeToSortedArr(root.left,res)
    }
};
```
