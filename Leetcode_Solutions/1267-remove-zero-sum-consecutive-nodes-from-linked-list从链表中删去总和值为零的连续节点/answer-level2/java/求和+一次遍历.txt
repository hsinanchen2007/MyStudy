### 解题思路
每次累计家，记录sum；相同的sum在下一次出现时，说明，这两段之间是0，可以去掉并做合并。
比较易错的点在于，有些记录过的sum在某一次合并已经被去掉了，需要清理。不然会出现废弃节点与某个节点的错误合并。

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
    public ListNode removeZeroSumSublists(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode dummy = new ListNode();
        dummy.next = head;

        //the same sum is stored in its first
        Map<Integer, ListNode> sumNodeMap = new HashMap<Integer, ListNode>(8);
        sumNodeMap.put(0, dummy);
        Map<ListNode, Integer> nodeSumMap = new HashMap<ListNode, Integer>(8);

        int sum = 0;
        ListNode node = head;
        while (node != null) {
            sum += node.val;
            nodeSumMap.put(node, sum);

            ListNode preNode = sumNodeMap.getOrDefault(sum, null);
            if (preNode == null) {
                sumNodeMap.put(sum, node);
            } else {
                //remove bad store
                ListNode tempNode = preNode.next;
                while(tempNode!=node&&tempNode!=null){
                    int tempSum = nodeSumMap.get(tempNode);
                    sumNodeMap.remove(tempSum);
                    tempNode = tempNode.next;
                }
                //remove link
                preNode.next = node.next;
            }

            node = node.next;
        }

        return dummy.next;
    }
}

```