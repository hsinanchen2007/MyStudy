这是中等题？分明是简单题送分题。。

```js
var levelOrder = function(root) {
    const res = [];
    if(!root) return res;
    const queue = [root];
    let front, i;
    while(queue.length) {
        i = queue.length;
        while(i--) {
            front = queue.shift();
            res.push(front.val);
            front.left && queue.push(front.left);
            front.right && queue.push(front.right);
        }
    }
    return res;
};
```
