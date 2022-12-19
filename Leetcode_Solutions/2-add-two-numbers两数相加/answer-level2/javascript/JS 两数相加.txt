```
var addTwoNumbers = function(l1, l2) {
    var nowNode = new ListNode();
    var carry=0,sum=0;
    var result = nowNode
    while(l1||l2||carry){
        sum = (l1?l1.val:0) + (l2?l2.val:0) + carry
        nowNode = nowNode.next = new ListNode(sum%10)
        carry = sum > 9 ? 1 : 0
        l1 = l1?l1.next:null
        l2 = l2?l2.next:null
    }
    return result.next
};
```