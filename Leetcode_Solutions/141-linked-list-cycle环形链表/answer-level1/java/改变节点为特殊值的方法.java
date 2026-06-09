官方题解的快慢指针法等就不说了，说了一个我自己的思路，本题因为ListNode有一个val值，可以考虑将访问过来的值改变成一个特殊值，如果再遇到这个值则认为是有环，时间复杂度O(N)，空间复杂度O(1)，不好的地方是，会改变链表的值，而且如果测试用例中有Integer.MAV_VALUE则无法通过。实际应用中，如果是高频判断是有环的话，可以考虑增加节点字段，比如boolean visited = false;来解决。一点想法，还请各位指点。
附代码如下：

```java []
public class Solution {
    public boolean hasCycle(ListNode head) {
        int visited = Integer.MAX_VALUE;
        ListNode flag = head;
        while(flag != null){
            if(flag.val == visited){
                return true;
            }
            flag.val = visited;
            flag = flag.next;
        }
        return false;
    }
}
```

