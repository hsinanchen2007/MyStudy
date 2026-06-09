### 解题思路
此处撰写解题思路
快慢指针，指向同一对象证明有环形结构，否者快指针指向null 或者是指向的节点的next为null证明是没有环的

看了官方题解，有个NB解法
大致意思是，获取当前节点的下一个节点，并且当前节点指向当前节点，然后将之前获取的下一个节点进行重复递归，如果出现自身闭环证明原链表有环，
    如果出现下一个节点为null证明单向链表
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        // 本题解决思路使用快慢指针的方式，如果链表有环结构，那么两个指针一定会相遇
        if(head == null ||head.next == null ){
            return false;
        }
        ListNode slowNode = head.next;
        ListNode fastNode = head.next.next;
        while(slowNode != fastNode){
            if(fastNode== null || fastNode.next == null){
                return false;
            }
            slowNode = slowNode.next;
            fastNode = fastNode.next.next;
        }
        return true;

    }
}
```