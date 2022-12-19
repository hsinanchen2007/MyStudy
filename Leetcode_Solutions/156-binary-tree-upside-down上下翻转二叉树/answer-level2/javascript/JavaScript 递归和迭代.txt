递归和迭代两种方法

不管是递归还是迭代，都需要明白，在 `k` 层上，最左边的节点有 left 和 right，假设为 `k.left` 和 `k.right`，那么变换后 `k.left` 作为父节点有左儿子 `k.right`，右儿子 `k`。

```
newParent = k.left
newParent.left = k.right
newParent.right = k
```
实际上 `newParent` 的左右是不能直接复制的，因为有原先的左右儿子，所以要先做保存
```
//当前以 k 层为父节点，处理 k 层

nextParent = k.left
k.left = tempRight
tempRight = k.right
k.right = tempLeft
tempLeft = k
k = nexParent

```

具体代码如下
```
var upsideDownBinaryTree = function (root) {
    let tempRight = null
    let tempLeft = null
    let nextParent
    while (k) {
        nextParent = k.left
        k.left = tempRight
        tempRight = k.right
        k.right = tempLeft
        tempLeft = k
        k = nexParent
    }
    return parent
};

```

递归

这里递归需要用一个全局变量在递归到最里层时把新的 `root` 节点给带出来，同时递归参数 `root` 表明 `root` 以下的节点都已经上下翻转好了，需要处理 `root` 节点，将其赋值给返回值的的 left 和 right。这里应该可以先处理 root 以上的，留坑。

```
var newRoot
var upsideDownBinaryTree = function (root) {
    recursive(root)
    return newRoot
};

function recursive(root) {
    if (root == null || root.left == null) {
        newRoot = root
        return root
    }

    let parent = recursive(root.left)
    parent.right = root
    parent.left = root.right
    root.left = null
    root.right = null
    return parent.right 
}
```