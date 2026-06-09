```
k个节点一组反转相当于对k个节点每次把头节点放在尾部节点后面，
所以只需要3个指针分别指向头节点的前一个节点pre，头节点p和尾部节点q,循环k-1此就把一组k长度节点链表反转。
```

 
- 例如 k=3 
- head = [1,2,3,4,5]
- 每组循环k-1 = 2次  [1,2,3]
- [1,2,3]--> [2,3,1]-->[3,2,1]
- [4,5]长度小于3不用循环
- 结果 [3,2,1,4,5]

```java []
public ListNode reverseKGroup(ListNode head, int k) {
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        if(k==1){
            return preHead.next;
        }
        ListNode pre = preHead;  //指向头部前一个节点
        ListNode p = pre.next; //指向头部第一个节点
        ListNode tail = head;  //指向尾部的最后一个节点
        boolean flag = true;
        while (flag) {
            // k-1 次循环
            for (int i = 1; i < k; i++) {
                if (tail == null || tail.next == null) {
                    flag = false;
                    break;
                }
                tail = tail.next;
            }
            if (!flag || tail==null)
                continue;
            //下一次循环的头节点
            p = tail.next;
            pre = reverseKnode(pre, tail, k);
            tail = p;
        }
        return preHead.next;
    }

    //将head的length长度节点交换
    public ListNode reverseKnode(ListNode preHead, ListNode tail, int length) {
        ListNode p = preHead.next;
        ListNode res = p;
        
        //循环更新length - 1次节点
        for (int i = 0; i < length - 1; i++) {
            ListNode tmp = tail.next;
            preHead.next = p.next;
            tail.next = p;
            p.next = tmp;

            //更新p,无需更新q
            p = preHead.next;
        }
        return res;
    }
```

