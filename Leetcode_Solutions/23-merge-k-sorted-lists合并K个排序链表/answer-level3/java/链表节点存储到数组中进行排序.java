### 解题思路
1.将链表数据转存到数组中；
2.对数组排序；
3.排序后的链表节点重新连接起来。

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

    public int getListLength(ListNode list) {
        ListNode iter = list;
        int count = 0;

        while (iter != null) {
            count++;
            iter = iter.next;
        }

        return count;
    }


    public ListNode mergeKLists(ListNode[] lists) {
        int listNum = lists.length;

        // 计算节点总数；
        int nodeCount = 0;
        for (ListNode list : lists) {
            nodeCount = nodeCount + getListLength(list);
        }
        if (nodeCount == 0) {
            return null;
        }

        // 将所有节点放到数组中
        ListNode[] nodeArray = new ListNode[nodeCount];
        int pos = 0;
        for (ListNode list : lists) {
            ListNode node = list;
            while (node != null) {
                nodeArray[pos] = node;
                pos++;
                node = node.next;
            }
        }

        // 对节点进行排序
        Arrays.sort(nodeArray, (node1, node2) -> {
            if (node1.val > node2.val) {
                return 1;
            } else if (node1.val < node2.val) {
                return -1;
            } else {
                return 0;
            }             
        });

        // 将排序好的链表重新链接起来
        ListNode head = nodeArray[0];
        ListNode tail = head;
        tail.next = null;
        for (int i = 1; i < nodeArray.length; i++) {
            tail.next = nodeArray[i];
            tail = tail.next;
            tail.next = null;
        }

        return head;
    }
}
```