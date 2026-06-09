### 代码

```javascript
var swapPairs = function(head) {
    if (head === null || head.next === null) {
        return head;
    }
    const next = head.next;
    // 递归函数的关键在于，假设该递归函数已经完成了需要它完成的功能
    // 这里假设 swapPairs 函数已经实现了交换相邻节点的功能
    // 则 swapPairs(next.next) 拿到的就是head.next.next 的重组链
    head.next = swapPairs(next.next)
    next.next = head;
    return next;
};
```