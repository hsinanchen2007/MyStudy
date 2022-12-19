### 解题思路
![WX20200216-001723@2x.png](https://pic.leetcode-cn.com/e32f034909f107cdd5b40254eb818524d16e360afe8343126d384c314497bc42-WX20200216-001723@2x.png)



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
        if(head == null || head.next == null){
            return head;
        }
        ListNode node = head;
        ListNode post = null;
        
        while(node !=null){
            ListNode next = node.next;
            node.next = post;
            post = node;
            node = next;

        }
        return post;
    }
}
```