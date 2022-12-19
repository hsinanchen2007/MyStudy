### 解题思路
 链表转数组 => 数组逆序删除arr[n-1]并还原顺序 => 数组转链表
### 代码

```javascript
var removeNthFromEnd = function(head, n) {
    const arr = []
    while (head) {
        arr.unshift(head.val)
        head = head.next
    }
    arr.splice(n - 1,1).sort((a, b) => a - b)
    let res = null
    for (let i = 0; i < arr.length; i++) {
        let current = new ListNode(arr[i])
        current.next = res
        res = current
    }
    return res
};
```