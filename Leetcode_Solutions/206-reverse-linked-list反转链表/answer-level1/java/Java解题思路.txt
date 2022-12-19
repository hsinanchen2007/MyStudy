### 解题思路
两种反转列表的方法：  
方法一是遍历原列表，然后将遍历的节点作为头节点插入到新链表；  
方法二是使用三个指针p0,p1,p2，每次令p1指向p0，p2的作用就是记录p1的next；

### 代码

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        // 方法一：逐个将旧链表的节点插入到新链表
        // ListNode new_head = null;  //新链表的尾节点
        // while(head!=null){
        //     ListNode tmp = head;  //记录节点
        //     head = head.next;  //遍历后移
        //     tmp.next = new_head;  //将节点放入新链表表头
        //     new_head = tmp;  //更新新链表的表头
        // }
        // return new_head;

        //方法二：使用三指针遍历
        if(head==null) return head;
        ListNode p0 = null;  //新链表的尾节点
        ListNode p1 = head;  //原链表的表头
        ListNode p2 = head.next;  //原链表表头的next
        while(p1!=null){
            p1.next = p0;
            p0 = p1;
            p1 = p2;
            if(p2!=null){
                p2 = p2.next;
            }
        }
        return p0;
    }
}
```