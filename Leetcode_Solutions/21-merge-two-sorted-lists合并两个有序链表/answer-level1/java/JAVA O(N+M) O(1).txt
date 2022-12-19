### 解题思路
边界条件：两个都是null，返回任意  一个为null，返回非null
创建一个dummyhead，必须这么做因为后面每一轮我们连向从剩余2个列表中最小那个来构筑链表， 如果开始直接将头设为最小那个再连向两个list最小的会造成环

### 代码

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode dummyhead = new ListNode(-1);
        ListNode cur = dummyhead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                cur.next = l1;
                l1 = l1.next;//l1 remain
            } else {
                cur.next = l2;
                l2 = l2.next;//l2 remain
            }
            cur = cur.next;
        }
        cur.next = l1 == null ? l2 : l1;//一个l会先变成null 连向非null的节点
        return dummyhead.next;
    }
}
```