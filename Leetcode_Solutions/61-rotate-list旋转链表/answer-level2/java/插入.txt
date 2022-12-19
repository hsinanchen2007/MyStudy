可以利用先构早一个dummyNode节点，然后每一次都插在dummyNode与其后面的节点之间，每一次需要保证插入的永远是最后一个，利用三个指针
1 2 3 4 5 | 0 -> 1 -> 2 -> 3 -> 4 -> 5
第一次：0 5 1 2 3 4
第二次：0 4 5 1 2 3 返回dummyNode.next即可
PS：时间复杂度有点大-_-||
```
public static ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        
        ListNode dummyNode = new ListNode(0);
        dummyNode.next = head;
        ListNode cur = dummyNode;
        ListNode res = head;
        int num = 0;
        while(res.next.next != null){
            num += 1;
            res = res.next;
        }
        num += 2;// 最后为空时，后面两个节点加入

        // 0 1 2 3 4 5 无论移动多少次，都是一直在往0后面插入
        // 永远保证最后一个节点一直在往前插！必须一直往前进
        ListNode p1 = res;
        ListNode p2 = p1.next;
        int n = k%num;
        while(n-- > 0){
            // 执行插入到dummyNode后一个节点位置
            p1.next = p2.next;
            p2.next = cur.next;
            cur.next = p2;
            // 找到p1之前的节点
            while(p2.next != p1){
                p2 = p2.next;
            }
            // 保证p1 p2永远在链表的最后两个节点
            p1 = p2;
            p2 = p2.next;
        }
        return dummyNode.next;
    }
```