### 解题思路
已知链表有序
1. 设定一个指向当前节点的指针
2. 当链表为空时退出循环
3. 如果下一个节点的值与上一个节点的值相等，删除下一个节点
4. 如果不相等，跳过下一个节点继续遍历

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
        ListNode current = head;
        while(current != null && current.next != null){
            if(current.next.val == current.val){
                current.next = current.next.next;
            }else{
                current = current.next;
            }
        }
        return head;
    }
}
```