### 解题思路

遍历链表，借助一个数组存储每一个节点，遍历完成后直接数组的size大小除2即可得到中间节点的下标

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
        if (head == null){
            return null;
        }
        List<ListNode> listNodes = new ArrayList<>();
        ListNode tempNode = head;
        while (tempNode!=null){
            listNodes.add(tempNode);
            tempNode = tempNode.next;
        }
        int total = listNodes.size();
        return listNodes.get(total/2);
    }
}
```