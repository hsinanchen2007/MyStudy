var sumOfLeftLeaves = function(root) {
    let sums = 0;
    let aa = sum(root);
    function sum(roots){
        if(roots&&roots.left){
            sums+=roots.left.val
            sum(roots.left)
        }
        if(roots&&roots.right){
            sum(roots.right)
        }
    }
    return sums
};