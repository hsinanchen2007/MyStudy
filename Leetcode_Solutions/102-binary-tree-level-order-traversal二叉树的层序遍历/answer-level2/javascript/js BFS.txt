```
var levelOrder = function(root) {
    const queue = [root];
    const res = [];
    let i = queue.length;
    while(i) {
        let temp = [];
        while(i--) {
            const front = queue.shift();
            if(!front) continue;
            temp.push(front.val);
            queue.push(front.left, front.right);
        }
        i = queue.length;
        temp.length && res.push(temp);
    }
    return res;
};
```
