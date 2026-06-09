### 解题思路
此处撰写解题思路
大概的方法就是基本的双指针法，一个快指针一次走两步，一个慢指针一次走一步，当快指针遍历完后，慢指针刚好到中间
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
        ListNode first = head;//快指针
        ListNode second = head;//慢指针
        while(first.next != null){//循环遍历 当快指针下一个位置为空时刚好循环完毕
            if(first.next.next != null){//当快指针下一‘步’不为空时，证明可以继续向前
                first = first.next.next;
                second = second.next;
            }else{//当快指针下一步为空时，证明它到了链表的倒数第二个位置，且此链表为偶数
                second = second.next;
                break;
            }
        }
        return second;
    }
}
```