### 解题思路
![新建位图图像.bmp](https://pic.leetcode-cn.com/ec92c4d33e0c190c682123a771cf103223448ee621750efcf5690a3d6d843f9c-%E6%96%B0%E5%BB%BA%E4%BD%8D%E5%9B%BE%E5%9B%BE%E5%83%8F.bmp)
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null ||head.next==null)return null;
       
        
        ListNode fast=head.next.next;
        ListNode slow=head.next;
        while(fast!=slow){
            if(fast==null||fast.next==null)return null;
            slow=slow.next;
            fast=fast.next.next;
        }

        ListNode t=head;
        while(t!=slow){
            t=t.next;
            slow=slow.next;
        }
        return slow;
    }
    
}
```