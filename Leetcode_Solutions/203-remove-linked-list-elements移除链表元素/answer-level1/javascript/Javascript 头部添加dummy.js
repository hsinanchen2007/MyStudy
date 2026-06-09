```
var dummy = {},
    prev = dummy,
    curt = head
//相当于给dummy一个指向，方便最后返回
prev.next = head

while (curt) {
    if (curt.val == val) {
        prev.next = curt.next
        curt = prev.next
    } else {
        prev = curt
        curt = curt.next
    }
}

return dummy.next
```
