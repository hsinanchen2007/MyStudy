### 解题思路
    使用双指针分别遍历两个链表，一旦某个指针到达了链表尾部，则该指针去交替遍历另一个链表：
    保证了每个指针到达第一个公共节点的总步长是一致的，可以在两个指针相等时返回第一个公共节点；
    也保证了每个指针到达链表的公共尾部的总步长也是一致的，可以在两个指针相等时返回空引用，表示两条链表不存在公共节点；

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        /* 使用双指针分别遍历两个链表，一旦某个指针到达了链表尾部，则该指针去交替遍历另一个链表
         * 保证了每个指针到达第一个公共节点的总步长是一致的，可以在两个指针相等时返回第一个公共节点
         * 也保证了每个指针到达链表的公共尾部的总步长也是一致的，可以在两个指针相等时返回空引用，表示两条链表不存在公共节点
         */
        ListNode nodeA = headA, nodeB = headB;

        while (nodeA != nodeB)
        {
            // 注意这里，一个指针到达链表尾部之后要交替扫描另一个链表
            nodeA = nodeA == null ? headB : nodeA.next;
            nodeB = nodeB == null ? headA : nodeB.next;
        }
        return nodeA;
    }
}
```