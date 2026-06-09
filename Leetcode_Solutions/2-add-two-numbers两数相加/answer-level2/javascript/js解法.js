```
var addTwoNumbers = function(l1, l2) {
    var res = new ListNode(0)
    var now = res
    while(l1 || l2 || now){
        var a = l1.val || 0
        var b = l2.val || 0
        var sum = a+b+now.val
        now.val = sum%10
        l1 = l1.next || 0
        l2= l2.next || 0
        if(sum > 9){
            now.next = new ListNode(1)
        }else if(l1 || l2) {
            now.next = new ListNode(0)
        }
        now = now.next
    }
    return res
};
```
