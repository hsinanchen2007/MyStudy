### 解题思路
* 创造一个哑巴节点，用来挂载排序的列表
* 要记录前一个节点做删除用

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
    public ListNode insertionSortList(ListNode head) {
        ListNode dummyNode = new ListNode(Integer.MIN_VALUE);

        ListNode crawlNode = head;
        ListNode sortedHead = dummyNode;
        ListNode sortedCrawl = dummyNode;
        while (crawlNode != null) {
            //System.out.printf("%d\n",crawlNode.val);
            ListNode lastNode = dummyNode;
            boolean insert = false;
            sortedCrawl = dummyNode;
            ListNode crawlNext = crawlNode.next;
            while (sortedCrawl != null) {
               if(crawlNode.val <= sortedCrawl.val) {
                   insert = true;
                   ListNode next = Objects.nonNull(lastNode) ? lastNode.next : null;
                   lastNode.next = crawlNode;
                   crawlNode.next = next;
                   break;
               }
               lastNode = sortedCrawl;
               sortedCrawl = sortedCrawl.next;
            }
            if( !insert ) {
                // 追加到链表末尾
                crawlNode.next = null;
                lastNode.next = crawlNode;
                sortedCrawl = crawlNode;
            }
            crawlNode = crawlNext;
        }
        return dummyNode.next;
    }
}
```