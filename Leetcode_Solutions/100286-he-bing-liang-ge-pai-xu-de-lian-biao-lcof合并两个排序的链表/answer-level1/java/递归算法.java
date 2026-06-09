### 解题思路
递归算法 用一个新的指针来保存合并的代码 新链表的next指向下一个比较后的节点，如果是l1的节点则l1指针往后移动，如果是l2的节点则将l2的指针后移。

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
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)
        return l2;
        if(l2==null)
        return l1;
        ListNode newNode;
        if(l1.val<l2.val){
            newNode = l1;
            newNode.next = mergeTwoLists(l1.next,l2);
        }else{
            newNode = l2;
            newNode.next = mergeTwoLists(l1,l2.next);
        }

        return newNode;

    }
}
```