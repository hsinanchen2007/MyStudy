**递归的时候带上层次值作为递归参数，直接作为结果数组中的索引。**<br>
```
/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    var nums = [];
    search(nums,root,0);
    return nums;
};

function search(nums,node,k){
    if(node == null){
        return;
    }
    if(nums[k]==undefined){
        nums[k] = [];
    }
    nums[k].push(node.val);
    for(var i = 0;i < node.children.length;i++){
        search(nums,node.children[i],k + 1);
    }
}
```
