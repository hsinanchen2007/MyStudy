### 解题思路
这道题目有助于更好地理解链表，如果不设置哨兵结点，我们将无法找到该链表的前继结点，因此设置一个哨兵，便于我们在重复值在表头时，找到前继结点，进而找到该值，比如，如果首结点为重复值，我们尝试把前继结点指向当前结点的下一个结点，同时当前结点自动向下进一位，也就意味着此时的前继结点的下一个结点和此时的当前结点指向同一个数值，即第二个结点，而如果头结点不是重复的话，那就更简单了，把前继结点直接指向当前结点，此时的前继结点和当前结点指向同一个数值，即首结点，那么当前结点还要继续往右移动一位，判断下一个结点是否是重复值，我想官方解题看的不是太懂得看看我这个再画画图也许就明白了。

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
    public ListNode removeElements(ListNode head, int val) {
       ListNode first = new ListNode(0);//这是一个头结点,也可以叫做哨兵结点
       first.next = head;
       ListNode prev = first;
       ListNode current = head;
       while(current!=null) {
           if(current.val==val) {
               prev.next = current.next;
           }else {
               prev = current;
           }
           current = current.next;
       }
       return first.next;

    }
}
```