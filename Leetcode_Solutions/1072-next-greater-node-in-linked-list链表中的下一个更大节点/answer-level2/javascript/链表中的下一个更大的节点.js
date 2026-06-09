
```
var nextLargerNodes = function(head) {
    var arr=[]
    while(head){
        var x=head.val;
        var curr=head;
        while(curr){
            if(x<curr.val){
                x=curr.val
                break;
            }
            curr=curr.next;
        }
        if(x==head.val){arr.push(0)}else{arr.push(x)}
        head=head.next;
        
    }
    return arr
};
```
