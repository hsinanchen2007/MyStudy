```javascript
const buildTree = function(inorder, postorder) {
    if(!inorder.length || !postorder.length) return null;
    return BTReconstruct(inorder, postorder, postorder.length - 1, 0, inorder.length - 1);
};

function BTReconstruct(inorder, postorder, postEnd, inStart, inEnd) {
    if(inStart > inEnd || postEnd < 0) return;
    let curr = new TreeNode(postorder[postEnd]);
    let idx = inStart;
    while(idx<=inEnd) {
        if(inorder[idx] === postorder[postEnd]) break;
        idx++;
    }
    
    curr.right = BTReconstruct(inorder, postorder, postEnd - 1, idx + 1, inEnd) || null;
    curr.left = BTReconstruct(inorder, postorder, postEnd - (inEnd - idx +1), inStart, idx -1) || null;
    
    return curr;
}
```