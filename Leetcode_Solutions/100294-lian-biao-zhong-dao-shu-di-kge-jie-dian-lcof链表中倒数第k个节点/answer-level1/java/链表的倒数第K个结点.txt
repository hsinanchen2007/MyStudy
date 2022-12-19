### 解题思路
创建一个哨兵结点，找到倒数第k大的数，就是正数第n-k个数
从头遍历链表 k--:
- k=0时，说明就是头节点；
- k>0时，没有倒数第K大的数；
- k<0时，node = head,k++，当k==0时，返回对应结点即可，k+n-k=n;
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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode node = head;
        while(node!=null){
            node = node.next;
            k--;
        }
        if(k>0) return null;
        else if(k==0){
            return head;
        }else{
            node = head;
            while(k++!=0){
                node = node.next;
            }
        }
        return node;
    }
}
```