### 解题思路
转中间件组面试遇到的,可惜从毕业后这半年就没有刷过题了。
虽然能想到是双指针,当时没有想到用哑结点来初始化双指针的指向。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //这儿有个头结点非常舒服
        ListNode emptyNode = new ListNode(0);
        emptyNode.next = head;
        ListNode leftPoint = emptyNode;
        ListNode rightPoint = emptyNode;
        while(rightPoint.next != null) {
            //移动右指针k个长度
            if(n-- > 0) {
                rightPoint = rightPoint.next;
                continue;
            }
            leftPoint = leftPoint.next;
            rightPoint = rightPoint.next;
        }
        // 3 --> 5。
        leftPoint.next = leftPoint.next.next;
        return emptyNode.next;
    }
}
```