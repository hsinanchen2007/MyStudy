**快慢指针** 
本题是NO.83删除排序链表中的重复元素的姊妹题，区别在于当出现重复的时候将发生重复的节点全部删除。

慢指针slow指向哑节点，fast指向head并遍历链表。

如果fast节点的值等于fast下一个节点的值则继续遍历。

否则值不相等或者fast已到达结尾的时候有两种情况：

1. fast和slow不相邻，指针之间存在重复的元素，则删除发生重复的节点，即`slow.next=fast.next`。

   ![GVn2yn.png](https://pic.leetcode-cn.com/d258b190f2379ac38c0732dea071ae0f6e60e68742ad4bef083b3bb357e0700e.png)

2. fast和slow相邻，则移动slow到fast的位置。

   ![GVngQs.png](https://pic.leetcode-cn.com/0d093f646b5d61a397a04f81110a4653f42c203b3f6a85e03db762803e6bb058.png)

循环直至fast遍历链表完毕。

```java
public ListNode deleteDuplicates(ListNode head) {
    if (head==null||head.next==null)return head;
    ListNode dummy=new ListNode(-1);
    dummy.next=head;
    ListNode fast=head,slow=dummy;
    while (fast != null) {
        //如果fast和下一个节点的值不同或者fast到达链尾，有两种情况
        if (fast.next == null || fast.val != fast.next.val) {
            //指针相邻
            if (slow.next == fast) {
                slow=fast;
            }else {//指针不相邻，删除中间的发生重复的节点
                slow.next=fast.next;
            }
        }
        fast=fast.next;
    }
    return dummy.next;
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和源码:[github](https://github.com/Jerrymouse1998/learning-record-of-leetcode) 	