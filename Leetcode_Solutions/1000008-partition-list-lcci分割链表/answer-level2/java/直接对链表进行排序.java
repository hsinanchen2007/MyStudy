### 解题思路
1.取出链表中所有的值
2.进行排序
3.替换原链表的值

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
    public ListNode partition(ListNode head, int x) {
        ListNode cur = head;
        ArrayList<Integer> list = new ArrayList<>();
        while(cur != null) {
            list.add(cur.val);
            cur = cur.next;
        }
        Collections.sort(list);
        cur = head;
        int inx = 0;
        while(cur != null) {
            cur.val = list.get(inx);
            inx++;
            cur = cur.next;
        }
        return head;
    }
}
```