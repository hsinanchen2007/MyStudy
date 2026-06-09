/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
    var arr = [];
    arr = inOrder(root);
    var result = [];
    for(var i = 0 ; i < arr.length ; i++){
      if( arr[i] < L || arr[i] > R ) continue;
      result.push(arr[i]);
    }
    var sum = 0;
    for(var i = 0 ; i < result.length ; i++){
        sum = sum + result[i];
    }
    return sum
};
function inOrder(root,array = []){
    if(root){
        inOrder(root.left,array);
        array.push(root.val);
        inOrder(root.right,array);
    }
    return array;
}