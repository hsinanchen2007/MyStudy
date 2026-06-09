```java
/*
 * @lc app=leetcode.cn id=83 lang=java
 *
 * [83] 删除排序链表中的重复元素
 * 解题思路：
 * 1. 若 链表 为空，则 return null;
 * 2. 若 链表 不为空，则遍历链表；
 *  2.1 设当前节点为 nextNode, 上一个节点为 preNode
 *  2.2 比较 nextNode 和 preNode 的 val 值是否相同
 *   2.2.1 若相同（说明存在重复元素，应删除nextNode），则让 preNode 指针指向 nextNode 下一个元素;
 *   2.2.2 若不同（说明不存在重复元素，不需要删除节点，但作为比较位的preNode应右移一位），则让 preNode 指针 指向 nextNode;
 * 3. 返回结果
 */

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        ListNode preNode = head;
        ListNode nextNode; // 用于记录循环中当前节点数据
        while ((nextNode = preNode.next) != null) {
            if (preNode.val == nextNode.val) { // nextNode 节点与 preNode 节点 val 值相等
                preNode.next = nextNode.next; // 删除 nextNode 节点，并使 preNode 指向 nextNode 的下一个节点
            } else { // nextNode 与 preNode 的 val 不相等
                preNode = nextNode; // 则 preNode 就直接指向 nextNode
            }
        }
        return head;
    }
}
```