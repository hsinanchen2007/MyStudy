

js hash表：

```
var hasCycle = function(head, pos) {
    if(!head) return false
    if(pos=== -1) return false
    if(head && pos === 0) return true
    const map = new Map()
    let sentry = false
    while(head) {
      if(map.has(head)) {
          sentry = true
          break
      } 
      map.set(head, 1)
      head = head.next
    }
    return sentry
};
```

js 快慢指针：

```
var hasCycle = function(head, pos) {
    if(!head) return false
    if(pos=== -1) return false
    if(head && pos === 0) return true
    let slow = head
    let fast = head
    while(slow && fast && fast.next) {
        slow = slow.next
        fast = fast.next.next
        if(slow === fast) {
           return true
         
        }
    }
    return false
};
```

