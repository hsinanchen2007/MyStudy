### 代码

```javascript
var levelOrder = function(root) {
    const res = [];
    const queue = [];
    let level = 1;
    if(root == null) return res;
    queue.push(root);
    while(queue.length){
        let temp = [];
        let len =queue.length;
        for(let i = 0; i < len; i++){
            let node = queue.shift();
            if(level % 2 === 1){
                temp.push(node.val);
            }else{
                temp.unshift(node.val);
            }
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);
        }
        res.push(temp)
        level++;
    }
    return res
};
```