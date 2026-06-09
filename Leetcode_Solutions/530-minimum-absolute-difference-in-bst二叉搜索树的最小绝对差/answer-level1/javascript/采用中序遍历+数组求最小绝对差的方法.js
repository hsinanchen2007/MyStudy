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
    var arr = [];
    arr = inOrder(root);
    var minVal = Number.MAX_VALUE;
    for(var i = 0 ; i < arr.length-1 ; i++){
        if( minVal > arr[i+1]-arr[i]) minVal = arr[i+1]-arr[i];
    }
    return minVal
};

function inOrder(root,array = []) {
    if(root){
        inOrder(root.left,array);
        array.push(root.val);
        inOrder(root.right,array);
    }
    return array;
}
