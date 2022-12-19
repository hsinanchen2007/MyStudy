将二叉树每一层（先左后右）依次存入数组，再从头取出判断是否为空
```js
var CBTInserter = function(root) {
    this.root = root;
};
CBTInserter.prototype.insert = function(v) {
    var arr = [];
    arr.push(this.root);
    var res = root.val;
    while(arr.length !== 0){
        var node = arr.shift();
        if(!node.left){
            res = node.val;
            node.left = new TreeNode(v);
            break;
        }else if(!node.right){
            res = node.val;
            node.right = new TreeNode(v);
            break;
        }
        if(node.left){
            arr.push(node.left);
        }
        if(node.right){
            arr.push(node.right);
        }
    }
    return res;
};
CBTInserter.prototype.get_root = function() {
    return this.root;
};
```