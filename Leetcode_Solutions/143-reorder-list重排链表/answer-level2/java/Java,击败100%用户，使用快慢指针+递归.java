    以1->2->3->4->5->NULL为例
 1. 先使用快慢指针法寻找出最后一个不需要改动的节点，即3
 2. 分割链表1->2->3->NULL , 4->5->NULL
 3. 递归会保存每次遍历到的节点，即4，5都会被递归函数每次递归保存下来，当递归到5时，使用head头节点进行依次插入
 4. 由于递归不会保持head的后面需要插入的节点，每次递归都需要遍历到需要插入的位置，此时使用返回值的方式，讲每次需要插入的位置进行返回，所以当递归不是5时，则使用返回的链表进行插入当前的node。（见下面代码）
```
        if (head == null || head.next == null || head.next.next == null) return;
        ListNode left = head.next;
        ListNode right = head.next;
        while (right != null && right.next != null) {
            right = right.next;
            if (right.next == null) break;
            right = right.next;
            left = left.next;
        }
        ListNode node = left.next;
        left.next = null;   //left表示答案的最后一个元素，需要和后面的节点断开
        //此时
        //head : 1->2->3->NULL
        //node : 4->5->NULL
        addList(head,node);
    }

    /**
     * 每次递归都会保存当前的node节点，
     * 当node为最后一个节点时开始使用@head参数进行插入
     * 当node不为最后一个节点则使用返回的@return进行插入
     * @param head 传递头节点，只在node.next==null处使用
     * @param node 返回已经处理好的前面的节点
     * @return  返回下一次需要修改的位置
     */
    public ListNode addList(ListNode head, ListNode node) {
        ListNode n = null;
        ListNode next = null;
        if (node.next != null) {    //当node不是最后一个节点时候，使用返回的链表进行修改
            n = addList(head, node.next);   
            next = n.next;  //next保存head的下一个节点
        } else {    //当node为最后一个节点时，即为5时
            n = head;   //使用head参数，1->2->3->NULL
            next = head.next;   //next保存head的下一个节点
        }
        n.next = node;  
        node.next = next;   
        return next;    //返回下一次需要修改的位置
    }
```