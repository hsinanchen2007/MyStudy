感觉比较low 用了一点js特性，和reverse。
但是代码量 应该是算少的了。
```js
var levelOrderBottom = function(root) {
    if (!root) return [];
    let arr = [];
    function work (tree, index) {
        if (!arr[index]) arr[index] = [];
        arr[index].push(tree.val);
        if (tree.left) {
            work(tree.left, index + 1);
        };
        if (tree.right) {
            work(tree.right, index + 1);
        }
    }
    work(root, 0);
    return arr.reverse();
};
```
