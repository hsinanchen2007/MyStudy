### 解题思路
1. 遍历链表得到链表的长度，并且将链表的尾部和头部相接得到一个环形链表
2. 计算应该在哪个位置将环形链表断开，需要注意的k的值可能大于count的值、所以我们必须要将k做模运算。

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
    public ListNode rotateRight(ListNode head, int k) {

        //先将链表做成一个环，然后开始数组在指定的位置将环形链表断开环就可以
        ListNode cur = head;
        int count = 1;
        if ( head==null ||head.next == null){
            return head;
        }
        while (cur.next != null){
            count++;//记录链表的长度
            cur = cur.next;
        }
        cur.next = head;//将链表形成一个环
        //然后开始数在指定的位置将环断开
        k = k%count;
        for (int i = 0; i < count - k -1;i++){
            head = head.next;
        }
        ListNode result = head.next;
        head.next = null;
        
        return result ;
    }
}
```