```
var zigzagLevelOrder = function(root) {
    if(!root) return [];
    const queue = [root];
    let i = queue.length;
    let isPositive = false;
    const res = [];
    while(i) {
        isPositive = !isPositive;
        let temp = [];
        while(i--) {
            const front = queue.shift();
            if(!front) continue;
            isPositive ? temp.push(front.val) : temp.unshift(front.val);
            queue.push(front.left, front.right);
        }
        temp.length && res.push(temp);
        i = queue.length;
    }
    return res;
};
```
