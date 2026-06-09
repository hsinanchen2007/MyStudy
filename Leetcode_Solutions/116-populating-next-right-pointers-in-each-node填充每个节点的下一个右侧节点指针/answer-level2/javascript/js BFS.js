```
var connect = function(root) {
    if(!root) return null;
    const queue = [root];
    let i = queue.length;
    let pre;
    while(i) {
        pre = null;
        while(i--) {
            const front = queue.shift();
            if(!front) continue;
            if(!pre) pre = front;
            else {
                pre.next = front;
                pre = pre.next;
            }
            queue.push(front.left, front.right);
        }
        i = queue.length;
    }
    return root;
};
```
