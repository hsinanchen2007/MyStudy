### 解题思路
代码写的有点乱，步骤就是：
1.找到链表的长度
2.遍历链表，返回长度匹配的剩余链表

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
        //判断点怎么找 长度
        if(head == null || head.next == null){
           return head;
        }
        int len = 0 ;
        ListNode src = head;
        while(head != null){
        len++;
        head = head.next;
        }
        if(len <= k){
        return src;
        }
        int tem = 0;
        while(src != null){
          if(tem == (len - k)){
              return src;
          }
          tem++;
          src = src.next;
        }
        return src;
    }
}
```