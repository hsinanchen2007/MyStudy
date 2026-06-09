1. 定义两个辅助指针, `prev`和`cur`, 如图
2. 通过`cur`遍历链表
    - 如果当前节点不等于下一个节点, `cur = cur.next`
    - 如果当前节点等于下一个节点, 循环执行 `cur = cur.next`, 直到`cur.val != cur.next`, 此时`cur`指向相同节点的最后一个,对应到图中最后一个`3`,此时还要执行一次`cur=cur.next`
3. 此时需要判断一下`prev`跟`cur`之间是否相隔一个节点
    - 如果相隔一个节点, 表示`cur`并没有进入2中的循环, 把`prev`指针往前移动一格就好了 `prev = prev.next`
    - 否则的话, `prev`不需要移动, 只需要把`prev`的`next`指针指向`cur`就好了 `prev.next = cur`, 对应到图中的最后一步
4. 最后返回`dummyHead.next`

![链表 (2).jpg](https://pic.leetcode-cn.com/33f2e48b297204dd5822d06169f89f94df9471b6252da3a5a4483c3b071d9d94-%E9%93%BE%E8%A1%A8%20\(2\).jpg)


```
class Solution {
     public ListNode deleteDuplicates(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        ListNode cur = dummyHead.next;

        while ( cur != null ) {
            while ( cur.next != null && cur.val == cur.next.val )
                cur = cur.next;

            cur = cur.next;

            if ( prev.next.next == cur )
                prev = prev.next;
            else {
                prev.next = cur;
            }

        }

        return dummyHead.next;
    }
}
```

最后想说一句, 对于我这种脑子转的慢的人, 画图真的太耗时间, 然后我是真的尽力地想把整个过程给描述清楚了, 不知道能不能帮到别人, 至少是记录了自己思考问题的一个过程
