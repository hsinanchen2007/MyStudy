简单题
```js
var levelOrder = function(root) {
    const res = [];
    if(!root) return res;
    const queue = [root];
    let front, i, temp, level = false;
    while(queue.length) {
        i = queue.length;
        temp = [];
        level = !level;
        while(i--) {
            front = queue.shift();
            temp.push(front.val);
            front.left && queue.push(front.left);
            front.right && queue.push(front.right);
        }
        res.push(level ? temp : temp.reverse());
    }
    return res;
};
```
