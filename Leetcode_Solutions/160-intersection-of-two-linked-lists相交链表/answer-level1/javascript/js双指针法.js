双指针法
```
var getIntersectionNode = function(headA, headB) {
    let flag1 = true, flag2 = true;
    if(!headA || !headB){
        return null
    }
    function tarverse(node1,node2){
        if(node1 == null){
            if(flag1){
                flag1=false;
                node1 = headB
            } else {
                return null;
            }
        }
        if(node2 == null){
            if(flag2){
                flag2=false;
                node2 = headA
            } else {
                return  null;
            }
        }
        
        if(node1 === node2){
            return node1;
        }
        
        return tarverse(node1.next,node2.next);
    }
    return tarverse(headA,headB)
};
```