# unshift从尾到头插入

```
var reversePrint = function(head) {
    let arr = []
    while(head)
    {
        arr.unshift(head.val)
        head = head.next
    }
    return arr
};
```

# 从头到尾插入reverse反转输出

```
var reversePrint = function(head) {
    let arr = []
    while(head)
    {
        arr.push(head.val)
        head = head.next
    }
    return arr.reverse()
};
```