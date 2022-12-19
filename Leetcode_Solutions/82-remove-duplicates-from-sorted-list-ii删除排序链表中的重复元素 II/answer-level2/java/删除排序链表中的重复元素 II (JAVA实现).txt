### 解题思路
![image.png](https://pic.leetcode-cn.com/ca9cd2bc8b4b0c5a88ee7093bccf8aa0796e8b75d03c1399a29fb06f57c12625-image.png)

思路：
  1、使用虚拟头节点指向head(以防止删除元素为首元素时逻辑不统一);
  2、初始化cur指针指向head,pre指针指向cur指针的前一个节点(初始时指向dummyHead)；
  3、然后循环遍历链表比较cur.val == cur.next.val;
  4、如果比较结果为相等，则进行删除操作(删除cur.next节点):cur.next = cur.next.next;然后继续循环遍历比较，
直到cur节点为链表尾节点或者cur.val != cur.next.val时，即进行删除cur指向节点的操作：pre.next = cur.next;
  5、如果比较结果不等，则移动pre和cur指针：pre = cur; cur = cur.next;
  6、返回dummyHead.next;(为何不直接返回head: 防止链表头节点被删除的情况发生)

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
        if(head == null || head.next == null) {
            return head;
        }
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        ListNode cur = dummyHead.next;
        while(cur != null && cur.next != null) {
          if(cur.val == cur.next.val) {
              cur.next =cur.next.next;
              // 删除到当前元素的下一个元素与其不等时，即可将当前元素删除
              // 注意判断cur.next是否为空，防止cur是最后一个元素，cur.next.val出现空指针异常
              if(cur == null || (cur.next != null && cur.val != cur.next.val)) {
                  pre.next = cur.next;
                  cur = pre.next;
              }
          }else {
              pre = cur;        // 暂存当前节点的前一个节点指针
              cur = cur.next;
          }
        }
        return dummyHead.next;
    }
}
```