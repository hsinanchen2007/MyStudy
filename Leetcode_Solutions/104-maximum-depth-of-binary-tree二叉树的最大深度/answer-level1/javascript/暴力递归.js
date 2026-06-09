
var maxDepth = function(root) {
    if(root === null) return 0
    
    function a(node,counter) {
        if(node.left === null && node.right === null) return counter
        if(node.left === null) return a(node.right,counter + 1)
        if(node.right === null) return a(node.left,counter + 1)
        return Math.max(a(node.left,counter + 1),a(node.right,counter + 1))
    }
    return a(root,1)
    
};