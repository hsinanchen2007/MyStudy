     采用首尾指针的方法，头尾插入皆为O(1), 越位限定， 没有实现双链表，没有太多意义，都是反复的码代码，直接贴代码了

![a.jpg](https://pic.leetcode-cn.com/af69ef38412cec278bd382c6555a8b12d264b37cdf349c65029c28f41958b2aa-a.jpg)

     
     
```
class MyLinkedList 
{
    
    private final ListNode list;
    private ListNode head;
    private ListNode rear;
    private int length;
    
    /** Initialize your data structure here. */
    public MyLinkedList() 
    {
        list = new ListNode(-1);
        list.next = new ListNode(-1);
        head = list;
        rear = list.next;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) 
    {
        if(index >= length || index < 0) return -1;
        ListNode result = head;
        for(int i = 0; i < index; i++)
        {
            result = result.next;
        }
        return result.next.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) 
    {
        ListNode newNode = new ListNode(val);
        newNode.next = head.next;
        head.next = newNode;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) 
    {
        rear.val = val;
        rear.next = new ListNode(-1);
        rear = rear.next;
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) 
    {
        if(index > length) return;
        if(index == length)
        {
            addAtTail(val);
            return;
        }
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        ListNode temp = head;
        for(int i = 0; i < index; i++)
        {
            temp = temp.next;
        }
        ListNode newNode = new ListNode(val);
        newNode.next = temp.next;
        temp.next = newNode;
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index)
    {
        if(index >= length || index < 0) return;
        ListNode temp = head;
        for(int i = 0; i < index; i++)
        {
            temp = temp.next;
        }
        ListNode node = temp.next;
        temp.next = node.next;
        length--;
    }
    
    private static class ListNode
    {
        ListNode next;
        int val;
        ListNode(int val)
        {
            this.val = val;
            this.next = null;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```
