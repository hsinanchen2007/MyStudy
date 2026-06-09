递归法很常规

```js
//     递归法
    var number = new Array();
    if(root == null) {
        return number;
    }
    
    function po(node, arr) {
        if(node == null) {
            return;
        }
        
        arr.push(node.val);
        for(var i = 0; i < node.children.length; i++) {
            po(node.children[i], arr);
        }
    }
    
    po(root, number);
    return number;
```

迭代法考虑使用链表实现。

首先把根结点作为链表头，然后按此循环：
1、遍历并删除链表头，如果该项有子结点，把它的所有子结点添加到链表头部；
2、如果链表为空，结束循环，否则重复1；

这样一来，就实现了树的遍历。
当然数组也可以实现这个功能，但是数组删除和添加的开销比链表大，所以**优先使用链表**来实现。

```js
var preorder = function(root) {
//     迭代法
    var number = new Array(); // 返回的数组
    if(root == null) {
        return number;
    }
    
    var link = [root]; // 此处应为链表；这里图方便使用数组实现。
    
    while(link.length) {
        // 取出链表的头
        let first = link.shift(); 
        number.push(first.val);
        if(first.children) { 
            // 如果有孩子，那么把孩子添加到头部
            for(let i = 0; i < first.children.length; i++) {
                link.splice(i, 0, first.children[i]);
            }
        }
    }
    
    return number;
};
```
