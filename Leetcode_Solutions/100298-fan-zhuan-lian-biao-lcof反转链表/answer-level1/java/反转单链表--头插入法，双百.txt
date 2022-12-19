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
    public ListNode reverseList(ListNode head) {
        //　边界处理
         if(head==null || head.next==null){
            return head;
        }


        ListNode temp = null;
        ListNode newNode = head.next;
        head.next = null;
        while(newNode.next!=null){
            temp = newNode.next;
            newNode.next = head;
            head = newNode;
            newNode = temp;
        }
        // 退出循环后，说明只有最后一个结点
        newNode.next = head;
        return newNode;       
    }
}
```