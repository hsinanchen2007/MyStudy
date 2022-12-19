思路：
1.先将链表翻转
2.遍历打印value
代码：
```
class Solution {
    public int[] reversePrint(ListNode head) {
        //先倒序，然后遍历打印
        if (head == null) return new int[0];
        ListNode pre = null;
        ListNode now = head;
        int size = 0;
        while (now != null) {
            ListNode next = now.next;//保存下一个节点
            now.next = pre;//将当前节点反向，指向前一个节点
            pre = now;//为下一轮做准备，将now设置为前一个节点
            now = next;//翻转下一个节点
            size++;//记录节点数量，用于为int res设置长度
        }
        int[] res = new int[size];
        int i = 0;
        while (pre != null ) {
            res[i++] = pre.val;
            pre = pre.next;
        }
        return res;
    }
}
```
