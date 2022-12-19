```
public class Solution {
   //检查是否有环用一个指针 时间复杂度是n 单个指针遍历所有节点将遍历过的节点的属性val赋上一个特殊值
//若在一次碰到这个特殊值 则说明环的存在 当然存在局限 若此链表中恰好存在该特殊值则该方法失效
    public boolean hasCycle(ListNode head) {
        if(head == null)
        return false;
        while(head.next != null)
        {
            if(head.next.val == Integer.MAX_VALUE)
                return true;
            head.val = Integer.MAX_VALUE;
            head = head.next;
        }
            return false;
    }
}
```