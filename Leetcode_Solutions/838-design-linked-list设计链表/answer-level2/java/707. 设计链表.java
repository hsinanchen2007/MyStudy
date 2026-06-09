/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/9
 *
 * 解题思路: 注意index 为负数的情况 直接插入到头部 其余的细心一点就行
 *
 */

```
class MyLinkedList {

    class list{
        list next;
        int val;
    }

    list list;
    list phead;

     /** Initialize your data structure here. */
    public MyLinkedList() {
        list = new list();
        phead = list;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        list = phead;
        int i = 0;
        while(list.next!=null){
            if(i++ == index){
                return list.next.val;
            }
            list = list.next;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        list in = new list();
        in.val = val;
        in.next = phead.next;
        phead.next = in;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        list = phead;
        list in = new list();
        in.val = val;
        while(list.next!=null){
            list = list.next;
        }
        list.next = in;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index < 0){
            addAtHead(val);
            return;
        }
        list in = new list();
        in.val = val;
        list = phead;
        int i = 0;
        while(list!=null){
            if(i++ == index){
                in.next = list.next;
                list.next = in;
                break;
            }
            list = list.next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        int i = 0;
        list = phead;
        while(list.next!=null){
            if(i++ == index){
                list.next = list.next.next;
                break;
            }
            list = list.next;
        }
    }
}
```