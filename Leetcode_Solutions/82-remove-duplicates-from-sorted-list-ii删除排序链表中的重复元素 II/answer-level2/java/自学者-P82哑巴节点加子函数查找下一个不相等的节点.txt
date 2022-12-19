### 解题思路
* 哑巴节点，无穷大和无穷小的使用
* 永远不变的记住前一个节点

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummyNode = new ListNode(Integer.MAX_VALUE);
        dummyNode.next = head;
        ListNode crawlNode = dummyNode.next;
        ListNode anchor = null;
        ListNode lastNode = dummyNode;
        while(crawlNode != null) {
            int nextVal = crawlNode.next !=null ? crawlNode.next.val : Integer.MIN_VALUE;
            if(crawlNode.val == nextVal) {
                ListNode next = findNextNode(crawlNode);
                lastNode.next = next;
                crawlNode = next;
            }else {
                lastNode = crawlNode;
                crawlNode = crawlNode.next;
            }
        }
        return dummyNode.next;
    }
    private ListNode findNextNode(ListNode crawlNode) {
        int val = crawlNode.val;
        crawlNode = crawlNode.next;
        while (crawlNode!=null) {
            if(crawlNode.val != val) {
                return crawlNode;
            }
            crawlNode = crawlNode.next;
        }
        return null;
    }
}
```