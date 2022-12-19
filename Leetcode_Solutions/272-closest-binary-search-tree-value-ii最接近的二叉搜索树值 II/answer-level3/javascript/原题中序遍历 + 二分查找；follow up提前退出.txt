## 原题：无时间要求，可以先用O(n)的方法
通过中序遍历将问题转换为在递增序列中找与target最接近的k个值
（类似的有658题）

js实现如下：时间复杂度O(n)
```javascript
var closestKValues = function(root, target, k) {
    const inorder = [];
    function dfs(node) {
        if (!node) return;
        dfs(node.left);
        inorder.push(node.val);
        dfs(node.right);
    }
    dfs(root);
    
    let l = 0;
    let r = inorder.length - k;
    while (l < r) {
        const mid = l + r >>> 1;
        if (target - inorder[mid] <= inorder[mid + k] - target) r = mid;
        else l = mid + 1;
    }
    return inorder.slice(l, l + k);
};
```


## follow up：要求时间小于O(n)
那么考虑在遍历bst的时候直接处理，并且提前退出。因为题目说了该bst是平衡的，所以提前退出一定是小于O(n)的
```js
var closestKValues = function(root, target, k) {
    const inorder = [];
    function dfs(node) {
        if (!node) return;
        dfs(node.left);

        if (target - inorder[0] <= node.val - target && inorder.length === k) return;

        inorder.push(node.val);
        if (inorder.length > k) inorder.shift();

        dfs(node.right);
    }
    dfs(root);
    return inorder;
}
```
