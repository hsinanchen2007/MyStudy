### 解题思路
做这个想到了数据结构-链表中的头插法插入数据，自己掌握不熟，，，，，，尝试了很久

### 代码

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current=head;          //当前元素所在位置
        ListNode rever=null,temp=null;  //rever反转后的头节点，temp用来储存current当前位置
        while(current != null)
        {
            temp=current.next;          //temp：当前节点的下一个节点
            current.next=rever;         //将当前节点的下一个指针域（JAVA不存在指针，个人习惯这样叫）指向rever,例：1->null
            rever=current;              //将当前节点位置传给rever
            current=temp;               //将current原始的下一节点位置给current
        }
        return rever;                   //bingo
    }
}
```