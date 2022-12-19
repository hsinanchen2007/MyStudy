直接把链表存在数组里,虽然存节点比较省内存,可是我就喜欢简单粗暴的

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
        ListNode[] arr = new ListNode[100];
        int i = 0;
        for(i = 0 ; head != null;i++){
            arr[i] = head;
            head = head.next;
        }
        return arr[i/2];

    }
}
```