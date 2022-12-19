### 解题思路
此处撰写解题思路
遍历两个链表，逐个比较并合并
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
        if(l1==null||l2==null){
            return l1==null?l2:l1;
        }
        ListNode listNode = new ListNode(0);
        ListNode ans = listNode;
        while(l1!=null||l2!=null){
            if(l1!=null&&l2!=null){
                if(l1.val<l2.val){
                    listNode.val = l1.val;
                    l1 = l1.next;
                }else {
                    listNode.val = l2.val;
                    l2 = l2.next;
                }
                listNode.next = new ListNode(0);
                listNode = listNode.next;
            }else if(l1==null){
                listNode.val = l2.val;
                listNode.next = l2.next;
                return ans;
            }else if(l2==null){
                listNode.val = l1.val;
                listNode.next = l1.next;
                return ans;
            }
        }
        return ans;
    }
}
```