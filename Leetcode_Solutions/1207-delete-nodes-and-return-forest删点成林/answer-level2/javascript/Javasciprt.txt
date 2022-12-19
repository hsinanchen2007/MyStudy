```
var delNodes = function(root, to_delete) {
    let forest = [];
    if( root && to_delete.indexOf(root.val) === -1 ) forest.push(root);
    function readTree(node, mother, dir) {
        if( to_delete.indexOf(node.val) > -1 ) {
            node.left && to_delete.indexOf(node.left.val) === -1 && forest.push(node.left);
            node.right && to_delete.indexOf(node.right.val) === -1 && forest.push(node.right);
            mother && dir && (mother[dir] = null);
        }
        node.left && readTree(node.left, node, 'left');
        node.right && readTree(node.right, node, 'right');
    }    
    readTree(root);
    return forest;
};
```