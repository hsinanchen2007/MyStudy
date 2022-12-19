### 代码

```javascript
var levelOrder = function(root) {
    const res = [];
    let temp = [];
    const queue = [];
    if(root == null) return res;
    queue.push(root);
    while(queue.length){
        let len = queue.length;
        temp = []
        for(let i = 0; i < len; i++){
            let node = queue.shift();
            temp.push(node.val);
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);
        }
        res.push(temp) 
    }
    return res
};
```