```javascript []
var invertTree = function (root) {
    let s1 = {}
    function sf(r, n) {
        if (n === null) return root
        r.val = n.val
        r.left = sf({}, n.right)
        r.right = sf({}, n.left)
        return r
    }
    sf(s1, root)
    return s1
};
/**
 * 该题主要使用递归思想，重新建树
 */
```

