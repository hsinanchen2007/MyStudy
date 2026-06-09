### 解题思路
step1. 遍历一遍获取链表的长度。
step2. 再次遍历到中间节点，然后返回。

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
    public ListNode middleNode(ListNode head) {
        int length = 0 ;
        ListNode tmp = head;
        while(tmp != null){
            length ++;
            tmp = tmp.next;
        }
        int nthMid = length/2 +1 ;
        tmp = head ;
        length = 0;
         while(tmp != null){
            length ++;
            if(length == nthMid){
                return tmp;
            }
            tmp = tmp.next;
        }
        return null;
    }
}
```