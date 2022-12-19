### 解题思路

先将单链表反转，然后输出。
![image.png](https://pic.leetcode-cn.com/622d449baaefb3337b04027e2d160746eeb3aa25ca001672f8edeb6fc98f1644-image.png)

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
    public int[] reversePrint(ListNode head) {

        ListNode pre = null;
        ListNode cur = head;
        int len = 0;
        while(cur != null){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
            len++;
        }
       
        int[] result = new int[len];
        int i = 0;
        while(pre != null){
            result[i] = pre.val;
            pre = pre.next;
            i++;
        }
        return result;

    }
}
```