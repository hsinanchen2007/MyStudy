var reversePrint = function(head) {
    var list=[];
    var cur=head;
    while(cur!=null){
        list.unshift(cur.val);
        cur=cur.next;
    }
    return list;
};