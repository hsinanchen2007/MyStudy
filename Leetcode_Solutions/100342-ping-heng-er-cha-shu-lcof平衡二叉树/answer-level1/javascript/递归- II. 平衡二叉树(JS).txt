```js
var isBalanced = function(root) {
    if(!root) return true;
    if(Math.abs(dep(root.left) - dep(root.right)) > 1) return false;
    return isBalanced(root.left) && isBalanced(root.right);
};
function dep(root) {
    if(!root) return 0;
    return Math.max(dep(root.left), dep(root.right)) + 1;
}
```