### 解题思路
虽然是让一趟遍历，但是中间还是要用一个函数来处理最好，遮掩思路比较清晰。
第一步：记录起点为止，为对接末尾元素做好准备
第二步：当要结束时，也就是到n时，将最后一个节点的next设置为null保证一个链表。
第三步：进行独立链表反转，相对清晰又简单。
第四步：进行前后对接，特别注意如果前置节点为null就直接把返回值赋值给head。

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head.next == null) {
            return head;
        }
        ListNode crawlNode = head;
        ListNode startNode = null;
        ListNode prevNode = null;
        ListNode prevStartNode = null;
        int cnt = 0;
        while(crawlNode!=null) {
            cnt++;
            if(cnt == m) {
                startNode = crawlNode;
                prevStartNode = prevNode;
            }
            if(cnt == n) {
                ListNode adjLastNode = crawlNode.next;
                crawlNode.next = null;
                ListNode newHead = reverseList(startNode);
                 if(prevStartNode==null) {
                    head = newHead;
                }else{
                    prevStartNode.next = newHead;
                }
                startNode.next = adjLastNode;
                break;
            }
            // 记录前置节点，为开始链表做准备
            prevNode = crawlNode;
            crawlNode = crawlNode.next;
        }
        
        return head;
    }
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode it = head;
        ListNode prev = null;
        ListNode nextNode = null;
        while(it != null) {
            //备份下一个节点
            nextNode = it.next;
            //下一个节点指向前一个节点
            it.next = prev;
            //设定当前节点为前一个节点
            prev = it;
            //跳转到下一个节点
            it = nextNode;
        }
        return prev;
    }
}
```