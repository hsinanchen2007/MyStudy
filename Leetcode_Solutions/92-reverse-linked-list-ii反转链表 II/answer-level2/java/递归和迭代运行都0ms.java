递归版本
```
    ListNode nextNode;
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode cur = head;
        ListNode start = null;
        ListNode end = null;
        int count = 1;
        while(cur!=null){
            if (count!=m){
                start = cur;
                cur = cur.next;
                count++;
            }else {
                end = cur;
                ListNode node = reverseListNode(cur,count,n);
                if (start!=null)
                    start.next = node;
                else head = node;
                end.next = nextNode;
                break;
            }
        }
        return head;
    }
    public ListNode reverseListNode(ListNode node,int count,int n){
        if (count==n){
            nextNode = node.next;
            return node;
        }
        ListNode listNode = reverseListNode(node.next,count+1,n);
        node.next.next = node;
        node.next = null;
        return listNode;
    }
```


迭代版本
```
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode cur = head;
        ListNode prev = null;
        ListNode start = null;
        ListNode end = null;
        int count = 1;
        while(cur!=null){
            if (count!=m){
                start = cur;
                cur = cur.next;
                count++;
            }else {
                end = cur;
                while (count<=n){
                    ListNode tempNext = cur.next;
                    cur.next = prev;
                    prev = cur;
                    cur = tempNext;
                    count++;
                }
                if (start!=null)
                    start.next = prev;
                else head = prev;
                end.next = cur;
                break;
            }
        }
        return head;
    }
```

懒得写注解哈哈！有人问我再来写哈哈
