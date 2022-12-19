[1,1]通过，拿到这个题，我的第一想法是赶紧给头节点整个前驱，然后对链表进行遍历，如果当前节点和后续节点不同，则更新pre，否则直到找到不同为止，然后将相同的全部删除；如果找不到不同的节点，说明已经到节点末尾了，直接将pre.next置为null即可。下面是我的运行结果以及代码：
![image.png](https://pic.leetcode-cn.com/f06ba87ef127803200dc87917858f68e0695404374c60e3cad20cb27b3806174-image.png)
```
public ListNode deleteDuplicates(ListNode head) {

        if (head == null || head.next == null){
            return head;
        }
        ListNode headHead = new ListNode(-1);
        ListNode pre = headHead;
        headHead.next = head;
        while (head != null && head.next!=null){
            if (head.val != head.next.val){
                pre = head;
                head = head.next;
            }else{
                while (head != null&&head.next != null&&head.val == head.next.val){
                    head = head.next;
                }
                if (head == null){
                    pre.next = null;
                }else{
                    pre.next = head.next;
                    head = head.next;
                }
            }
        }
        return headHead.next;
    }
```

