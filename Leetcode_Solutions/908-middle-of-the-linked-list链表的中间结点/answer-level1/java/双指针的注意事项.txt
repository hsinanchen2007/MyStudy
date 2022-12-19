### 解题思路
此处撰写解题思路
经典双指针问题，我就写一下需要注意的地方：
while循环条件时两个条件的先后顺序是固定的，不能随意改变。
如果先判断q.next!=null，对于偶数情况时q已经指向空指针，调用q.next就会报空指针的错误。
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
        ListNode p = head,q=head;
        while(q!=null&&q.next!=null){ 
            p=p.next;
            q=q.next.next;
        }
        return p;

    }
}

```