### 解题思路
本题使用List集合非常好做，因为关系到定位的问题，可类似于数组的方式求解，使用List集合存储结点，之后返回为个数除以2再加1减去1，因为List集合是从零开始遍历。

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
        List<ListNode> list = new LinkedList<ListNode>();
        ListNode current = head;
        int count = 0;
        while(current!=null) {
            list.add(current);
            current = current.next;
            count++;
        }
        count = count/2+1;
        return list.get(count-1);
    }
}
```