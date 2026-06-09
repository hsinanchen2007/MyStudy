var sortedArrayToBST = function(nums) {
if(nums.length===0){
        return null;
    }
    if(nums.lenngth === 1){
        return new TreeNode(nums[0]);
    }
    //寻找右中位数
    let mid = Math.floor((nums.length)/2);  
    const node = new TreeNode(nums[mid]);
    let left = nums.slice(0,mid);
    let right = nums.slice(mid+1);
    node.left = sortedArrayToBST(left);
    node.right = sortedArrayToBST(right);
    return node;
}