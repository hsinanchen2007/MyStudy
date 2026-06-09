### 解题思路
此处撰写解题思路

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
        if(head == null || k < 0) return null;
        if(k == 0 || head.next == null) return head;
        ListNode temp = head;
        ListNode resNode = head;
        //求取链表的总长度
        int length = 1;
        while(temp.next != null){
            temp = temp.next;
            length++;
        }
        //找寻右移的起始节点
        int start = 0;
        if(k <= length){
            start = length - k;
        }else{
            start = length - (k % length);
        }
        if (start == length) return head;
        //到达起始节点
        while(start != 0){
            resNode = resNode.next;
            start--;
        }
        //找到末尾节点,置为空
        ListNode tempRes = resNode;
        while(length != 1){
            tempRes.next = tempRes.next == null ? head : tempRes.next;
            tempRes = tempRes.next;
            length--;
        }
        tempRes.next = null;
        return resNode;
    }
}
```