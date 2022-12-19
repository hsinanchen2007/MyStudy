总的思路就是创建另一条链表用来存放原链表中的value,该value小于x
遍历原链表，遇到value<x就将其移出原链表，加入小链表。使用哑点的原因就是不用考虑空链表或者链表数为1的特殊情况
```
    public ListNode partition(ListNode head, int x) {
        ListNode originDummy = new ListNode(-1);
        //拼接
        originDummy.next = head;
        //定义指针
        ListNode originCur = originDummy;

        //定义第二个哑点
        ListNode smallDummy = new ListNode(-1);
        //保存头节点，用于返回
        ListNode smallHead = smallDummy;

        //将原链表的节点按与x的大小分发到两个哑点
        while (originCur.next != null) {
            //根据大小分发，由于originDummy设定为只保留>=的节点
            if (originCur.next.value < x) {
                //该节点小于x，所以要将其存放在smallDummy
                //调整originDummy,让next指向head的下一个
                // -1   1   4   3   2   5   2
                //也就是让-1指向4
                //但是这里必须保存1，因为要将1加入到smallDummy链表
                ListNode temp = originCur.next;
                originCur.next = temp.next;
                //将1加入到small
                smallDummy.next = temp;
                //移动指针
                smallDummy = smallDummy.next;

            } else {
                //当前节点(4)>x(3),所以不需要转到smallDummy上，直接移动指针
                originCur = originCur.next;
            }
        }
        //将OriginDummy连接到smallDummy后面
        smallDummy.next = originDummy.next;
        return smallHead.next;
```