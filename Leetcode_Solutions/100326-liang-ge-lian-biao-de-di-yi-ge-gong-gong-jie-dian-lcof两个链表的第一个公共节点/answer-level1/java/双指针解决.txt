## 4.两个链表的第一个公共节点 ##
### 图表分析 ###
![002.png](https://pic.leetcode-cn.com/c77f5824515b3c9a1b01e2227b66b8ae83c64058fa74213af6685aa07f58d587-002.png)
### 思路 ###
- 找到第一个相同的，就是找第一个地址相同的指针
- 但是有可能两个链表长度不一样
- 所以每个链表后面接上另一个链表，就可以补齐
- 如果在前面，就可以正常对比到
- 如果在后面，在A循环完成，立马补一个B上去

### 代码
```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
           if (headA == null|| headB==null)
        {
            return null;
        }
        ListNode nodea = headA;
        ListNode nodeb = headB;

        while (nodea!=nodeb)
        {
            nodea = nodea==null ? headB:nodea.next;
            nodeb = nodeb==null ? headA:nodeb.next;
        }


        return nodea;
    }
}
```

