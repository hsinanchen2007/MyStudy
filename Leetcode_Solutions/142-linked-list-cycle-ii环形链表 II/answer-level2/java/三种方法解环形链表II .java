### 142. 环形链表 II Medium

### 方法1：Hash
> Hash存一下ListNode
```
public ListNode detectCycle(ListNode head) {
    Set<ListNode> set = new HashSet<>();
    ListNode node = head;
    while (node != null) {
        if(set.contains(node) ) return node;
        set.add(node);
        node = node.next;
    }
    return null;
}
```




### 方法2：快慢指针（Floyd 算法）
>第一步：找到快慢指针相遇的节点，如果找不到，证明没有环，返回null
>第二步：head节出发与slow节点出发，相遇的节点为环的入口节点
```
 public ListNode detectCycle(ListNode head) {
         if (head == null||head.next==null) return null;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast.next != null && fast.next.next != null) {
            if (slow == fast) break;
            slow = slow.next;
            fast = fast.next.next;
        }
        if (slow != fast) return null;
        while (head != slow.next) {
            head = head.next;
            slow = slow.next;
        }
        return head;
    }
```



### 方法3：快慢指针（普通法）
```
public ListNode detectCycle2nd(ListNode head) {
    if (head == null || head.next == null) return null;
    //step1：快慢指针找到相遇的节点，没有找到相遇的节点，证明不成环，返回null
    ListNode slow = head;
    ListNode fast = head.next;
    ListNode tmp = null;
    while (fast.next != null && fast.next.next != null) {
        if (fast == slow) {
            tmp = slow;
            break;
        }
        slow = slow.next;
        fast = fast.next.next;
    }
    if (fast != slow) return null;
    //step2:找到环的step
    int step = 1;
    ListNode cur = tmp.next;
    while (cur != tmp) {
        cur = cur.next;
        step++;
    }
    slow = head;
    fast = head;
    //step3：将fast指针移动step步
    for (int i = 0; i < step; i++) {
        fast = fast.next;
    }
    //step4:slow与fast指针同步走，相交即为环的入口
    while (slow != fast) {
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
}
```


