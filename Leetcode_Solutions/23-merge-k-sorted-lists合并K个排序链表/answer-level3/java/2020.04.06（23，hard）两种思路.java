### 解题思路
本题使用两种解法

第一种是**优先队列**：
- 利用优先队列的特性可以使多个链表每次都将**最小结点出队**，具体参考代码注释

第二种是**分治思想**：
- 只需遍历一半数组，每次将**左右两端合并**放到左端位置,之后在向中间移动,直到**到达中间位置**,然后数组减半
- 其中**合并链表**为基本思想，具体代码很好理解，剩下的着重体现在注释上。

### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if (lists == null || len == 0) {
            return null;
        }
        // 使用优先队列对链表进行排序（排序算法）
        PriorityQueue<ListNode> pq = new PriorityQueue<>(len,new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val < o2.val) {
                    return -1;
                } else if (o1.val == o2.val) {
                    return 0;
                } else {
                    return 1;
                }
            }
        });
        // 创建带头结点的新链
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        // 将原来链表的结点放入新链
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }
        while (!pq.isEmpty()) {
            // 头结点后面接每次出队的元素
            p.next = pq.poll();
            p = p.next;
            // 此时 p.next 指向上面出队元素的后一个结点（可参考weiwei哥图解）
            if (p.next != null) {
                pq.add(p.next);
            }
        }
        return dummy.next;
    }
}
```
```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if (len == 0) {
            return null;
        }    
        // 每次将链表的两头合并起来放到左端链表
        while(len > 1) {
            for (int i = 0; i < len / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            // 最后合并完后链表长度减半
            len = (len + 1) / 2;
        }
        // 最后所有的结点都会存放在最左端位置
        return lists[0];
    }
    
    // 合并两个链表
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        if (l1 != null) {
            p.next = l1;
        } else if (l2 != null) {
            p.next = l2;
        }
        return dummy.next;
    }
}
```