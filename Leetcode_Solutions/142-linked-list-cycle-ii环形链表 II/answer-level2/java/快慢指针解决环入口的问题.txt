### 解题思路
首先如果有环形结构，那么快慢指针两者必定相遇（快是慢的两倍）
1.整个链表长度设置为L，头到环入口为x，环入口到相遇点为a，环的长度为r，快是慢的两倍
快走的距离 sf:x+a+n*r(n为圈数,n>1)
慢走的距离 sm:x+a
2(x+a) = x+a+n*r;
x=n*r-a;
x=(n-1)*r+L-x-a;其中L-x-a代表的是从相遇点走向入口点的距离
假设两个指针分别在头和相遇点，每次都走1步，由于没有走圈，所以两者一定会在入环出相遇

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
    public ListNode detectCycle(ListNode head) {
        // 快慢指针的思想
        ListNode firstNode = head;
        if(head == null || head.next ==null){
            return null;
        }
        ListNode fastNode = head.next.next;
        ListNode slowNode = head.next;
        while(fastNode != slowNode){
            if(fastNode == null || fastNode.next ==null){
                return null;
            }
            fastNode = fastNode.next.next;
            slowNode = slowNode.next;
        }
        ListNode secodeNode = fastNode;
        while(firstNode != secodeNode){
            firstNode = firstNode.next;
            secodeNode = secodeNode.next;
        }
        return firstNode;
    }

}
```