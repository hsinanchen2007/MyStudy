### 代码

```javascript
var kthLargest = function(root, k) {
    if(root == null || k < 1) return null;
    let arr = [];
    const getTree = (root) => {
        if(root.left) getTree(root.left);
        arr.push(root.val);
        if(root.right) getTree(root.right);
    }
    getTree(root);
    return arr.reverse()[k - 1]
};


```