### 解题思路
/**
 * 1.建立一个HashMap，前面多项和sum为key，此节点d作为value，组成 (sum,d)
 * 如果出现好多相同的(sum,d)，后面的覆盖前面的
 * 2.第二遍遍历哈希表，如果sum和哈希表里面的sum相同，找到sum对应的结点的next作为d.next;
 * 3.返回链表的头结点
 */

### 代码

```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        Map<Integer,ListNode> map = new HashMap<>();
        int sum = 0;
        for(ListNode d = dummy;d!=null;d = d.next){
            sum += d.val;
            map.put(sum,d);
        }
        sum = 0;
        for(ListNode d = dummy;d!=null;d = d.next){
            sum += d.val;
            d.next = map.get(sum).next;
        }
        return dummy.next;
    }
}
```