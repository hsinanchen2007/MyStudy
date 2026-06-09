新建头节点temp计算链表长度奇偶性，再遍历一次，分奇数偶数情况，找到正确的中间position值，直接返回head就行，其中已经包含了next各项

/**
Definition for singly-linked list.
    function ListNode(val) {
    this.val = val;
    this.next = null;
 }

 @param {ListNode} head
 @return {ListNode}
 **/
var middleNode = function(head) {
    var temp = head.next;
    var count = 0;
    var position = 0;
    while (temp) {
        temp=temp.next;
        count ++;
    }
    if(count % 2 ==0){
        while(head) {
            if(position == count/2){
                return head;
            }
            else {
                head=head.next;
            }
            position ++;
        }
    }
    else {
        if(count==1) {
            return head.next;
        } 
         while(head) {
            if(position == (count+1)/2){
                return head;
            }
            else {
                head=head.next;
            }
             position ++;
        }
    }
};