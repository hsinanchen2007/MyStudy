### 解题思路
一次遍历，时间复杂度O(n),在所有 Java 提交中击败了98.64%的用户。主要是每一轮的while循环初始状态是p指向了某个值的第一个节点。

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
    
    public ListNode deleteDuplicates(ListNode head) {
        // 判断特殊情况
        if(head == null || head.next == null)return head;
        ListNode p = head;
        // dummyNode re
        ListNode re = new ListNode(0);
        ListNode r = re;
        while(p!=null){   // 遍历链表，每轮while循环遍历开始时p指向的是某个值的第一个节点
            int cur = p.val;
            if(p.next!=null && p.next.val!=cur){  // 判断当前节点是否为不重复节点，若当前节点满足要求，则将该节点保存到re中
                r.next = p; r = p; p = p.next; r.next = null;
            }else if(p.next!=null && p.next.val==cur){  // 当前节点的值重复出现，则直接遍历链表直到指向下一个值的第一个节点
                while(p!=null && p.val==cur){
                    p = p.next;
                }
                if(p==null){  // 当前该重复节点值为最大值的情况，即
                    return re.next;
                }
            }else{  // 即p.next==null的情况，即当前节点这个值在整个链表只出现一次
                r.next = p; r = p; p = p.next; r.next = null;
            }
        }
        return re.next;
    }
}
```