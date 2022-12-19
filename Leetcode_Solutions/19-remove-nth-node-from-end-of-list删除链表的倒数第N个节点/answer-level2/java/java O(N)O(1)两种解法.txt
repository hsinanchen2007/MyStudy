
单指针两次遍历O(N)时间O(1)空间
倒数第N=正数第(len+1-n) 遍历一遍获得长度 再遍历一遍找到要删除位置元素前一个元素进行删除操作

```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int length = 0;
        ListNode dummy_head = new ListNode(-1);
        dummy_head.next = head;
        ListNode cur = head;
        while(cur != null) {
            cur = cur.next;
            length++;
        }
        int NthFromBegining = length + 1 - n;
        if(NthFromBegining>length || NthFromBegining<1) return null;
        cur = dummy_head;
        for(int i = 1;i<=NthFromBegining-1;i++) {
            cur=cur.next;
        }
        cur.next = cur.next.next;
        return dummy_head.next;
    }
}
```
双指针一次遍历  O(N)O(1)   首先需要明白一个道理：指针2先走n-1步到正数第n个节点 两个指针同时滑行直到指针2到末尾节点，此时指针1一定指向要删除的倒数第n个节点。 按这个思路我们只需要将指针1滑到要删除节点前一个即可。  1个节点的链表：特殊情况处理
2个或以上：删除头节点或非头节点 分类讨论
```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null && n == 1) return null;//special case
        ListNode pt1 = head, pt2 = head;
        int length = 1;
        for(int i = 0; i < n - 1; i++) {
            pt2=pt2.next;
            length++;
        }//先移动指针2 n-1步 现在他指着正向第n个
        while(pt2.next != null && pt2.next.next!=null){
            pt2=pt2.next;
            pt1=pt1.next;
            length++;
        }//向后滑行同时计数获得链表长度
        if(pt2.next!=null && pt2.next.next==null) length++;//奇数个节点特殊情况会滑到倒数第二个节点停下
        if(n!=length) {//常规删除
            pt1.next = pt1.next.next;
        } else {//删除头节点
            ListNode temp = head.next;
            head.next = null; 
            head = temp;
        }
        return head;
    }
}
```
同样双指针一次遍历 使用dummyhead会简单很多 参考官方解。 主要思想：先移动一个指针pt1 n+1步使其位于第n+2个节点上，他与初始节点相隔n个节点  保持这个距离滑动 当pt1为null时 pt2刚好指向要删除节点前一个。
```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pt1 = dummy, pt2 = dummy;
        for(int i = 1; i <= n + 1; i++) pt1 = pt1.next;
        while(pt1 != null) {
            pt2 = pt2.next;
            pt1 = pt1.next;
        }
        pt2.next = pt2.next.next;
        return dummy.next;
    }
}
```
