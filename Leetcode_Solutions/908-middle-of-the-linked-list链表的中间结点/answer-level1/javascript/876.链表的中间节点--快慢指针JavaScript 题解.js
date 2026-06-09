用两个指针，快指针走两步，慢指针走一步，当快指针到终点时，慢指针正好在中间
```
var middleNode = function(head) {
    var low = head;
    var fast = head;
    while(fast&&fast.next){
        low = low.next; 
        fast = fast.next.next; 
    }
    return low;
};
```
