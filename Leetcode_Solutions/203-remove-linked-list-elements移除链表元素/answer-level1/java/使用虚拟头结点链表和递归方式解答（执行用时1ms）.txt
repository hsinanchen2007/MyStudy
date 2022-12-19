### 思路一：使用虚拟头结点快速解决
使用带有虚拟头节点的链表结构更容易解决此题。删除的思路很简单，找到待删除元素的前一个元素（prev），使用prev.next = prev.next.next; 删除即可。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public ListNode removeElements(ListNode head, int val) {
        //使用一个链表的虚拟头节点
        ListNode dummyHead = new ListNode(-1);
        //让head指向虚拟头结点
        dummyHead.next = head;
        //使用prev作为遍历，待删除元素的前一个元素
        ListNode prev = dummyHead;
        while(prev.next != null){
            if(prev.next.val == val)
                //如果值相同，那么删除prev的下一个元素
                prev.next = prev.next.next;
            else
                //如果不同，自增查找下一个元素
                prev = prev.next;
        }
        return dummyHead.next;
    }
}
```
### 思路二：使用递归实现解决

- 大问题为：删除链表中所有值为val的节点。
- 划分为对应小的问题是：链表的第一个节点为head，那么我们先head后面的那个链表的val值全部删除了得到res；然后再来判断第一个head是否应该删除，如果是，直接返回res；如果不是，head联通res一起返回
- 最最基础的问题就是：最后一个节点为null，那就是空链表，没有得删除，返回null

### 代码

```java
class Solution2 {

    public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return null;

        ListNode res = removeElements(head.next, val);
        if(head.val == val){
            return res;
        } else {
            head.next = res;
            return head;
        }
    }
}
```