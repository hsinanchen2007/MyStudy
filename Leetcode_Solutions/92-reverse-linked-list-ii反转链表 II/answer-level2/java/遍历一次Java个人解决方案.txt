### 解题思路
1、关键点在于记录链表断开的两个位置点。开始翻转前节点及第一个翻转的节点。
2、此处前提是n<=链表长度，则遍历到n节点即可结束遍历
3、翻转过程：当前节点的next指向前一节点，注意防止节点信息丢失
4、翻转完成后，重新连接断开点
5、需要考虑特殊情况，翻转的起点或终点与链表的头或尾重合。

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
        if(head == null || head.next == null || m == n){
            return head;
        }
        int i = 1;
        ListNode curNode = head;
        ListNode preNode = null;

        //翻转前的第一个节点
        ListNode rePreNode = null;
        ListNode startNode = null;

        //只需要遍历到待翻转结束节点或结尾
        while (i <= n && curNode != null){
            ListNode tempNode = curNode.next;
        
            if(i <= m){
                //没到到达m之前，记录
                rePreNode = preNode;
                startNode = curNode;
            }else {
                curNode.next = preNode;
            }
            preNode = curNode;
            curNode = tempNode;
            i++;
        }
        //重新连接尾部段开处
        startNode.next = curNode;
        //翻转前有节点，需要重新链接。
        if(rePreNode != null){
            rePreNode.next = preNode;
            return head;
        }else {
            return preNode;
        }
    }
}
```