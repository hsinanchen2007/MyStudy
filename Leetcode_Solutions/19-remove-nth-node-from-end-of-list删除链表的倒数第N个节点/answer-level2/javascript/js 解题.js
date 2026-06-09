```js
var removeNthFromEnd = function(head, n) {
    let arr = []
    let cur = head
    while(cur) {
        arr.push(cur) //当前项存在放入数组中
        cur = cur.next
    }
    let delNode = arr[arr.length - n - 1] //获取到需要删除的前一个节点
    delNode ? (delNode.next = delNode.next.next) : (head = head.next ) //删除操作
    return head
};
```

