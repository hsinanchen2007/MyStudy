Array.prototype.midNum = function(){
    return this[parseInt(this.length/2)]
}

Array.prototype.left = function(){
    return this.slice(0, parseInt(this.length/2))
}

Array.prototype.right = function(){
    return this.slice(parseInt(this.length/2+1))
}

var sortedArrayToBST = function(nums) {
    if (!nums.length)return null
    let node = new TreeNode(nums.midNum());
    node.left = sortedArrayToBST(nums.left());
    node.right = sortedArrayToBST(nums.right());
    return node
};