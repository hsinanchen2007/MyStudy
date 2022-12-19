1:因为不能改变给定的linked list的结构，因此需要一个新的链表。
2:因为需要逆序打印出链表，考虑到栈的LIFO的特点，因此需要引入栈来作为辅助结构。
```
public void printLinkedListInReverse(ImmutableListNode head) {
        
        Stack<ImmutableListNode> s=new Stack();
        while(head!=null){
            s.push(head);
            head=head.getNext();
        }
        ImmutableListNode newNode;
        while(!s.isEmpty()){
            newNode=s.pop();
            newNode.printValue();
            newNode=newNode.getNext();
        }
    }
```