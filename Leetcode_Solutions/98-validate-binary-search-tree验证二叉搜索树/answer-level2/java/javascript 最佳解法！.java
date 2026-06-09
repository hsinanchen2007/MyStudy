```
var isValidBST = function(root, leftMax = Number.MIN_SAFE_INTEGER, rightMin = Number.MAX_SAFE_INTEGER) {
    if(!root) return true;
    if(leftMax >= root.val || root.val >= rightMin) return false;
    
    return isValidBST(root.left, leftMax, root.val) && isValidBST(root.right, root.val, rightMin);
};
```
