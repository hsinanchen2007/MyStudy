


var kthToLast = function(head, k) {
    let fast = head,
        slow = head;
        for(let i = 0;i<k;i++){
            fast = fast.next;
        }
        while(fast !== null && slow !== null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow.val;
};