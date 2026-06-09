# 思路
- 链表按照『个十百千万』顺序存储数字
- 依次将两条链表对应结点相加，加和大于十的同时进位
- 递归需要一个进位参数，和两个对应节点的引用参数
- 递归终止条件是两条链表都到达终点
- 递归过程是将两个结点的数字与进位数相加；对10取余数创建新结点并返回；递归下一个结点并建立新链表

# 代码
```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return add(l1,l2,0);
    }
    public ListNode add(ListNode l1, ListNode l2, int a){
        if(l1 == null && l2 == null && a == 0) return null;
        int x = l1==null ? 0 : l1.val; 
        int y = l2==null ? 0 : l2.val;
        int sum = x + y + a;
        ListNode n = new ListNode(sum % 10);
        n.next = add(l1==null ? null : l1.next,
                     l2==null ? null : l2.next,
                     sum/10);
        return n;
    }
}
```