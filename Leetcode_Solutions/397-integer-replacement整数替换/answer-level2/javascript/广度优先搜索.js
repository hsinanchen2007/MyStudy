效率比贪心低，但更通用。

```javascript []
    var queue = [];
    var pushQueue = function(value, count){
        queue.push({
            n:value,
            c:count
        })
    };
    pushQueue(n, 0);
    while (queue.length > 0){
        let node = queue.shift();
        if (node.n == 1) return node.c;
        if (node.n & 1) {
            pushQueue(node.n + 1, node.c + 1);
            pushQueue(node.n - 1, node.c + 1);
        } else {
            pushQueue(node.n / 2, node.c + 1);
        }
    }
    return -1;
```

