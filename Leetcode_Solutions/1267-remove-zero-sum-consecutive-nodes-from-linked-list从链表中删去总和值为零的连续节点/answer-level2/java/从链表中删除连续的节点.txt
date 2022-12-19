### 解题思路
首次遍历建立 节点处链表和<->节点 哈希表
若同一和出现多次会覆盖，即记录该sum出现的最后一次节点
第二遍遍历 若当前节点处sum在下一处出现了则表明两结点之间所有节点和为0 直接删除区间所有节点
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
        ListNode dumary = new ListNode(0);
        Map<Integer, ListNode> map = new HashMap<>();
        dumary.next = head;
        int sum  = 0;
        for(ListNode d = dumary; d != null; d = d.next){
            sum += d.val;
            map.put(sum,d);
        }
        sum = 0;
        for(ListNode d = dumary; d != null; d = d.next){
            sum += d.val;
            d.next = map.get(sum).next;
        }
        return dumary.next;
    }
}
```