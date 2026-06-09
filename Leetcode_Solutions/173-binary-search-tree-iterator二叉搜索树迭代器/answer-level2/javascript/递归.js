```js
var BSTIterator = function(root) {
    this.arr = [];
    function dfs(root){
        if(!root) return;
        dfs.call(this, root.left);
        this.arr.push(root.val);
        dfs.call(this, root.right);
    }
    dfs.call(this,root);
};
BSTIterator.prototype.next = function() {
    return this.arr.shift();
};
BSTIterator.prototype.hasNext = function() {
    return this.arr.length !== 0;
};
```