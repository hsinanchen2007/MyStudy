### 解题思路
大概思路就是，每次遍历两个节点，相互交换，并且判断这两个节点上个节点是否为空，不为空的话，还需要修改上个节点的next值。

1. 确定这道题的边界
如果链表长度小于2，直接返回原链表

2. 定义辅助变量
2.1 最终结果，resultNode。
2.2 上个节点，初始值为空
2.3 因为java语言不像python那样支持直接交换两个值的语法，所以交换值需要第三个变量

3. 定义遍历的结束条件，当前要交换的两个节点都不能为空。
4. 遍历的处理逻辑，1.交换值，2.处理上个节点的next，设置下次遍历的节点

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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode resultNode = head.next; //最终结果的头节点
        ListNode preNode = null; // 上个节点
        ListNode tempNode;// 三个值交换需要一个第三个变量做缓存
        while(head != null && head.next != null) {
            //交换两个节点的next指针
            tempNode = head.next;
            head.next = head.next.next;
            tempNode.next = head;
            //如果上一个节点不为空，修改上个节点的next。
            if(preNode != null) {
                preNode.next = tempNode;
            }
            //记录下次交换的上个节点
            preNode = head; 
            //设置下一次遍历的头指针
            head = head.next;
        }
        return resultNode;
    }
}
```