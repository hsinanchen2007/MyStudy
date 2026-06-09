双指针解法，时间复杂度O(n+m)，空间复杂度O(1):

1. 维护两个指针pA和pB，初始分别指向A和B。然后让它们分别遍历整个链表，每步一个节点。
2. 当pA到达链表末尾时，让它指向B的头节点；类似的当pB到达链表末尾时，重新指向A的头节点。
3. 如果pA在某一点与pB相遇，则pA或pB就是交点。如果没有相遇，最后返回null。不会死循环。
4. 所以最多遍历链表A的长度+链表B的长度 即可判断出是否有相交的节点。

```
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pa = headA, pb = headB;
        while (pa != pb)
        {
            pa = (pa != null) ? pa.next : headB;
            pb = (pb != null) ? pb.next : headA;
        }
        return pa;
    }
}
```

复杂度分析
时间复杂度 : O(m+n)
空间复杂度 : O(1)

[微软-内推]（北京上海苏州无锡）大量职位招人，长期有效 https://leetcode-cn.com/circle/article/Cj79fP/