第一次迭代时候计数和建立一个反向链表
然后正向链表和反向链表各自迭代比较，出现不同就跳出返回false

```javascript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if(head==null)
        return true;
    let node=head;
    let l=1; //计数
    let tempNode=new ListNode(head.val)  //迭代的同时建立一个反转的链表
    let newListNode;
    while(node.next!=null){
        node=node.next;
        newListNode=new ListNode(node.val)
        newListNode.next=tempNode;
        tempNode=newListNode;
        l++;
    }
    //正反两个链表同时往中间迭代到长度的一半
    let mid=parseInt(l/2);
     for(let i=0;i<mid;i++)
    {
        if(head.val!=newListNode.val)
        return false;
        head=head.next;
        newListNode=newListNode.next; 
    }
        return true;
};
```
