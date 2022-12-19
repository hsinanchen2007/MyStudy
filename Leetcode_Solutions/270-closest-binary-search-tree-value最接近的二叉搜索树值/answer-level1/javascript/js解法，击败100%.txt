var closestValue = function(root, target) {
    var res = root.val;
    function scan(node){
        res = (Math.abs(target-node.val) > Math.abs(target-res)) ? res : node.val;
       if(target<node.val){
           node.left && scan(node.left);
       }else if(target>node.val){
           node.right && scan(node.right);
       }
    }
    scan(root);
    return res;
};