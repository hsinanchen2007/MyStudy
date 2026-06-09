这里当时分了三种情况去操作，后来发现中间一种可以合并到最后一种  
使用了额外变量`temp`保存返回值，以及使用`pre`保存前一个节点

```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null)
            return head;
        ListNode temp = head;
        ListNode pre = null;
        /**
         * 删除头节点
         * 删除尾节点
         * 删除中间节点
         */
        while (head != null) {
            if (head.val == val && pre == null) {
                temp = temp.next;// 删除头节点
            } 
            // else if (head.val == val && head.next == null) {
            //     pre.next = null;// 删除尾节点
            // } // pre.next=null 如果是尾节点则 head.next==null 因此合并到第三种情况
            else if (head.val == val) {
                pre.next = head.next;// 删除中间节点
            }else {
                pre=head;// 没有找到符合的节点
            }
            head = head.next;
        }
        return temp;
    }
}
```
