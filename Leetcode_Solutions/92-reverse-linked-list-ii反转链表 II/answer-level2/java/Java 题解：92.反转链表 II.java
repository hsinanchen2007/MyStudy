## 思路
 题目要求一次遍历完成链表反转，所以需要记录 m 的上一个位置，用于连接最终反转链表部分的头部，记录 m 的位置，用于连接 n 的下一个位置，再记录一个 m 的位置命名为 mn，用于反转链表。

  注意：由于 m 有可能有等于 1 的情况，所以需要对 1 进行特别判断。如果不想判断 1 的情况，那么还有另一种方法，加一个 ListNode 指向头部，此时就不用判断等于 1 的情况。

## 实现
```
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
        if (m == n){
            return head;
        }
        ListNode node = head;
        ListNode nodeStart = null;
        ListNode nodeM = null;
        ListNode nodeMN = null;
        for(int i = 1;i <= n; i++){
            ListNode temp = node;
            node = node.next;
            if (m == i && m != 1){
                continue;
            }
            if (n == i){
                nodeM.next = node;
                temp.next = nodeMN;
                if (m != 1) {
                    nodeStart.next = temp;
                    return head;
                }
                return temp;
            }
            if(nodeMN != null){
                temp.next = nodeMN;
                nodeMN = temp;
            }
            if (m - 1 == i || m == 1 && nodeMN == null){
                if (m == 1) {
                    nodeM = temp;
                    nodeMN = temp;
                }else {
                    nodeStart = temp;
                    nodeM = temp.next;
                    nodeMN = temp.next;
                }
            }
        }
        return head;
    }
}
```

