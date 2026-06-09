```javascript
let inorderTraversal = function(root) {
    if(!root) return [];
    let res = [],
        stack = [];
    helper(root, stack, res);
    return res;
};

let helper = function(root, stack, res) {
    if(!root) {
        let last = stack.pop();
        if(last)
            res.push(last.val);
        return;
    }
    stack.push(root);
    helper(root.left, stack, res);
    helper(root.right, stack, res);
}
```
