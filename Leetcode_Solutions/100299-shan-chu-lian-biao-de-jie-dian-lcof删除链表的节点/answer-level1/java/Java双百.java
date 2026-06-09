![WechatIMG3.png](https://pic.leetcode-cn.com/d42e713b16633cda2e2298ca7abe395cd2ec77090c11199e4b99ece720f2ed17-WechatIMG3.png)

### 解题思路
就是记录相等值节点的前一个节点
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
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null)
            return head;
        if(head.val == val)
            return head.next;
        ListNode pre = head;
        ListNode cur = pre.next;
        while(cur != null){
            if(cur.val == val){
                pre.next = cur.next;
                return head;
            }else{
                pre = cur;
                cur = cur.next;
            }
        }
        return head;
    }
}
```