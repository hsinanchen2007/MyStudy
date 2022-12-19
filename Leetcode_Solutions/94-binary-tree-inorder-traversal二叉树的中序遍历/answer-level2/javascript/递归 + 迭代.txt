// 递归
var inorderTraversal1 = function(root, res = []) {
    if(root !== null) {
        inorderTraversal(root.left, res);
        res.push(root.val);
        inorderTraversal(root.right, res);
    }
    return res;
};

// 迭代
var inorderTraversal = function(root) {
    var res = [];
    var stack = []; // 栈
    var cur = root;

    while(cur || stack.length > 0) {
        while(cur) {
            stack.push(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        res.push(cur.val);
        cur = cur.right;
    }
    return res;
}