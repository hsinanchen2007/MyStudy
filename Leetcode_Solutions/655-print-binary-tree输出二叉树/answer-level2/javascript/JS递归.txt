先获取数深度m二维数组行数，再根据n=2^m-1获取二维数组列数，根节点位于当前行数中位数，左子树为左侧中位数，右子树为右侧中位数，递归赋值
```js
var printTree = function (root) {
    var res = [];
    var m = getDepth(root, 0);
    var n = Math.pow(2, m) - 1;
    for (var x = 0; x < m; x++) {
        if (!Array.isArray(res[x])) {
            res[x] = [];
        }
        for (var y = 0; y < n; y++) {
            res[x][y] = "";
        }
    }
    set(root, 0, 0, n);
    return res;
    function set(root, n, start, end) {
        if(!root || start>end) return;
        var i = start + (end-start)/2>>0;
        res[n][i] = root.val+"";
        set(root.left, n+1, start, i-1);
        set(root.right, n+1, i+1, end);
    }
    function getDepth(root, count) {
        if (!root) return count;
        var l = getDepth(root.left, count + 1);
        var r = getDepth(root.right, count + 1);
        return Math.max(l, r);
    }
};
```