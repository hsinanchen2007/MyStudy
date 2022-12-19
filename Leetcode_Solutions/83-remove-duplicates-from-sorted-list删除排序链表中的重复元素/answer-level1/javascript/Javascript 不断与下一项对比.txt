```
var deleteDuplicates = function(head) {
    //让curt指向当前头结点
    var curt = head

    //当curt并且curt.next为true，也就是不为null的时候
    while (curt && curt.next) {
        if (curt.val == curt.next.val) {
            curt.next = curt.next.next
        } else {
            curt = curt.next
        }
    }

    //返回头结点
    return head
}
```
