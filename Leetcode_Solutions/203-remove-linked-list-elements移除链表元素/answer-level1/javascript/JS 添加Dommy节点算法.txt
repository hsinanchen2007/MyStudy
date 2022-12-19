思路来自Java大神
大致思路：表头加一个dummy node，用temp变量保存加了一个头节点的新链表，新建一个search指针头开始对temp除了头节点以外其他节点进行“删除”操作，及search.next = search.next.next;操作，这里需要注意，search节点只有在遇到了非删除节点时才向后移动，不然是固定不变的。

Definition for singly-linked list.
  function ListNode(val) {
    this.val = val;
    this.next = null;
 }

 @param {ListNode} head
 @param {number} val
 @return {ListNode}

var removeElements = function(head, val) {
    if(head == null) return null;
    var temp = {
        val: -1,
        next: head
    }
    var search = temp;
    while (search.next != null) {
        if(search.next.val == val){
            search.next = search.next.next;
        }
        else {
            search=search.next;
        }  
    }
    return temp.next;
};

