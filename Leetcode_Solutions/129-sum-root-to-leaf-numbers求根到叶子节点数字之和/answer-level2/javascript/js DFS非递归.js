```
var sumNumbers = function(root) {
    if(!root) return null;
    root.sum = root.val;
    const stack = [root];
    let i = stack.length;
    let res = 0;
    while(i) {
        while(i--) {
            const front = stack.pop();
            if(!front) continue;
            if(!front.left && !front.right) res += front.sum;
            if(front.left) front.left.sum = front.sum * 10 + front.left.val;
            if(front.right) front.right.sum = front.sum * 10 + front.right.val;
            stack.push(front.right, front.left);
        }
        i = stack.length;
    }
    return res;
};
```
