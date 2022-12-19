```
var removeNthFromEnd = function(head, n) {
    let first = head;
    let count = 0;
    let second = head;
    
    
    if(head.next == null){
        return null
    }
    
    do{
        if(count >= n ){
            second = second.next;
        }
        first = first.next;
        count++;
        
    }while(first.next!=null)
   
    if(count < n ){
       second = second.next;
       return second;
    }
    
    if(n == 1){
        second.next = null;
    }else{
        second.next = second.next.next;
    }
    
    return head;
};
```
