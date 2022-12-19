小白一个
先递归到最后一个，然后跟头比较。
```
var isPalindrome = function(head) {
    if(head === null) return true
    let copy = head
    let result = true
    let trace = function(copy) {
        if(copy === null) return true
        trace(copy.next)
        if(copy.val == head.val)
            head = head.next
        else{
            result = false
        }
    }
    trace(copy)
    return result
};
```
