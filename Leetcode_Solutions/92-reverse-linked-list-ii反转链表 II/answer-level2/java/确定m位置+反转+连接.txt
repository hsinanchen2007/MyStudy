![屏幕快照 2020-02-19 下午3.47.35.png](https://pic.leetcode-cn.com/65f758daad58573b9a91c19f14d97c59d5280e3f43d4a64a84bd0eb31e7ac3e6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-19%20%E4%B8%8B%E5%8D%883.47.35.png)

     * 1. newHead->head：建立新表头
     * 2. 确定m的位置的mNode，以及m前面的位置h
     * 3. 从m位置开始逐个反转pre->curr->next 到 curr->pre->next；反转n-m次
     * 4. 反转后: pre是反转部分的头，curr是后面没有反转的头
     * 5. 三个链表连接起来：h-> pre , mNode -> curr, 中间是反转部分(pre->...->mNode)

    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null || m==n){
            return head;
        }else if (head.next.next == null){
            if (m==1 && n==2){
                ListNode h = head.next;
                head.next = null;
                h.next = head;
                return h;
            }
            return head;
        }
        //1. newHead->head：建立新表头
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        //2. 确定m的位置的mNode，以及m前面的位置h
        ListNode h = newHead;
        int i = 1;
        while (i != m){
            h = h.next;
            i ++;
        }//此时：h是在m前面
        if (h == null || h.next == null || h.next.next == null){
            return head;
        }
        ListNode mNode = h.next;
        //3. 从m位置开始逐个反转pre->curr->next 到 curr->pre->next；反转n-m次
        //从m开始反转，反转后pre是头，curr是后面没有反转的头，
        //exchange pre and curr
        ListNode pre = h.next;
        ListNode curr = pre;
        ListNode next = curr.next;
        pre.next = null;
        while (i <=n){
            curr.next = pre;

            pre = curr;
            curr = next;
            if (curr == null){
                break;
            }
            next = curr.next;

            i ++;
        }//4. 反转后: pre是反转部分的头，curr是后面没有反转的头
        //curr.next = pre;
        //5. 三个链表连接起来：h-> pre , mNode -> curr, 中间是反转部分(pre->...->mNode)
        h.next = pre;
        mNode.next = curr;
        return newHead.next;
    }
