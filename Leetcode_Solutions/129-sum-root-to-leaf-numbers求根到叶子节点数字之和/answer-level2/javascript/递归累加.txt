深度遍历组合成字符串，叶子节点转换成number累加输出结果
```js
var sumNumbers = function(root) {
    var res = 0;
    dfs(root, '');
    return res;
    function dfs(root, str){
        if(!root) return;
        str += root.val;
        if(!root.left && !root.right){
            res += Number(str);
            return;
        }
        dfs(root.left, str);
        dfs(root.right, str);
    }
};
```