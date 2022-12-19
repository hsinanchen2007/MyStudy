
找出第一个大于等于x的节点A，遍历A后的节点，如果该节点的值小于x，则将该节点插到节点A的前面。
```
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode root=new ListNode(-1);
        root.next=head;
        ListNode slow=root;//slow用来找插入的位置
        while(slow.next!=null&&slow.next.val<x)//slow最终位置是第一个大于等于x节点的位置的前一个，方便后续插入
            slow=slow.next;
        if(slow.next==null)//如果是最后一个位置，返回原链表
            return root.next;
        ListNode fast=slow.next;//fast用来找小于x的节点
        while(fast.next!=null){
            if(fast.next.val<x){//所有slow位置后面的小于x的节点都往slow位置插
                ListNode temp=fast.next;
                fast.next=temp.next;
                temp.next=slow.next;
                slow.next=temp;
                slow=temp;
                continue;
            }
            fast=fast.next;
        }
        return root.next;
    }
}
```
