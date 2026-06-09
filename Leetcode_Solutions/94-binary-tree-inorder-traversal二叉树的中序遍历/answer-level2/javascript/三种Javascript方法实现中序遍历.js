### 什么是中序遍历？
先遍历左子树，然后访问根结点，最后遍历右子树


### 实现方式如下：
##### 一、 堆栈法（易理解）：
1. 如果存在左分支则入栈，并忘左跳  
2. 如果不存在左分支和右分支（即到底了）保存当前值并跳转回上一个节点（保存在栈中，出栈即可）并将这个节点的左分支设为null  
3. 如果只存在右分支，左分支为null则保存当前节点并忘右分支走

```Javascript
var inorderTraversal = function(root) {
    var res = [], stack = []
    while(root || stack.length) {
        if(root.left) {
            stack.push(root)
            root = root.left
        }else if(!root.left && !root.right) {
            res.push(root.val)
            root = stack.pop()
            // 这里等价于：if(root) root.left = null
            root && (root.left = null)
        }else if(root.right) {
            res.push(root.val)
            root = root.right
        }
    }
    return res
};
```
##### 二、 递归（实现简单）：
1. 先判断是否存在左分支，存在就往左分支走
2. 当左分支不存在时，将此时的值push进列表中，看是否还有右分支，如果有就递归执行右分支的node

```Javascript
var inorderTraversal = function(root, res = []) {
    if(!root) return []
    if(root.left){
        inorderTraversal(root.left,res);
    }
    res.push(root.val);
    if(root.right){
        inorderTraversal(root.right,res);
    }
    return res;
};
```


##### 三、 莫里斯遍历：
```Javascript
var inorderTraversal = function(root) {
    let arr = []
    let current = root
    while(current) {
        if(!current.left) {
            arr.push(current.val)
            current = current.right
            root = root.right
        }else{
            current = current.left
            root.left = null
            if(current.right) {
                let pointer = current.right
                while(pointer.right) {
                    pointer = pointer.right
                }
                pointer.right = root
            }else{
                current.right = root
            }
            root = current
        }
    }
    return arr
};
```