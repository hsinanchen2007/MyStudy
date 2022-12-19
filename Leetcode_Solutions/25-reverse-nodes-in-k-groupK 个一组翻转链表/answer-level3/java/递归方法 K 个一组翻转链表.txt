递归方法
```
public ListNode reverseKGroup(ListNode head, int k) {
        //判断个数
       int count = 0;
        ListNode temp = head;
        while (temp != null){
            count++;
            temp = temp.next;
            if (count == k-1)
                break;
        }
        //如果下一个为null说明个数不够直接返回
        if (temp == null)
            return head;
        int num = k;//保存翻转的次数
        temp = temp.next;//保存下一次递归的头节点
        ListNode headt = head;//保存递归后连接的头节点
        //这段为翻转链表的
        ListNode pre = null;
        while (num!=0){
            ListNode next = head.next;
            head.next = pre;
            pre = head;
            head = next;
            num--;
        }
        headt.next=reverseKGroup(temp,k);//修正之前翻转链表时将head节点的next
        return pre;
    }
```
