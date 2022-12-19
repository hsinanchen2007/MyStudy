```
var addTwoNumbers = function(l1, l2) {
    let nodelist = new ListNode(null) //{val:null,next:null}
    let result = nodelist
    let params = 0
    let value = 0
    while(l1||l2){
        let x = l1?l1.val:0;
        let y = l2?l2.val:0;
        value = (x + y + params )%10
        params = parseInt((x + y + params )/10)
        if(l1) l1 = l1.next;
        if(l2) l2 = l2.next;
        result.next = new ListNode(value) 
        result = result.next
    }
    if(params){
        result.next = new ListNode(params)
    }
    return nodelist.next
};
```
