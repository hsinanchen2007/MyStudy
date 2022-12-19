```
var middleNode = function(head) {
    //判断边界情况
    if(head===null||(head===null&&head.next===null))return 0
    //快慢指针
    let mid=head
    while(head!=null&&head.next!=null){
        mid=mid.next
        head=head.next.next
    }
    
    return mid
};
```