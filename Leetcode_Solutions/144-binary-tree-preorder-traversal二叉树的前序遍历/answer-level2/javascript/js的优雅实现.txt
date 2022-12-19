大家都喜欢自己熟悉的语言，我觉得js方便

## 递归太方便了
```javascript []
var preorderTraversal = function(root) {
    return root ? [root.val, ...preorderTraversal(root.left), ...preorderTraversal(root.right)] : []
};
```

## 迭代也还行
使用数组模拟栈，先放右节点，后放左节点
```javascript []
var preorderTraversal = function(root) {
    let arr = [], res = []
    root && arr.push(root)

    while(arr.length > 0) {
        let cur = arr.pop()
        res.push(cur.val)

        cur.right && arr.push(cur.right)
        cur.left && arr.push(cur.left)
    }
    return res
};
```









