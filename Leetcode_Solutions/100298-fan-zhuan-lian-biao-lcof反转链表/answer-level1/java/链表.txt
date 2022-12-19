### 解题思路
此处撰写解题思路
1.要设置三个指针，前指针，当前指针，下一个指针
2.next = cur.next 必须要写在 cur = next 前面 ，否则会报空指针异常
3.该方法是用遍历的思想实现，方法二：递归
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
    public ListNode reverseList(ListNode head) {
        ListNode pre  = null;
        ListNode cur = head;
        ListNode next = null;
        int count = 0; 
        while(cur !=null){
            next = cur.next;
            cur.next = pre;
            pre = cur ;
            cur = next;
        }
        return pre;
    }
}
```