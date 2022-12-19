#### 定义两个指针，一个遍历老链表，一个组合新链表，这样无需对原有链表进行删除

```java []

public ListNode deleteDuplicates2(ListNode head) {
        if(head == null){
            return head;
        }
        ListNode tmp = head;
        ListNode newHead = null;
        ListNode newHeadTmp = null;
        while(tmp!=null && tmp.next != null){
            if(tmp.val == tmp.next.val){
                while(true){
                    if(tmp.val != tmp.next.val){
                        tmp = tmp.next;
                        break;
                    }else{
                        tmp = tmp.next;
                    }
                    if(tmp.next == null){
                        tmp = null;
                        break;
                    }
                }
            }else{
                if(newHead == null){
                    newHeadTmp = newHead = tmp;
                }else{
                    newHeadTmp.next = tmp;
                    newHeadTmp = newHeadTmp.next;

                }
                tmp = tmp.next;
            }
        }
        if(newHeadTmp != null){
            newHeadTmp.next = tmp;
        }else{
            newHead = tmp;
        }
        return newHead;
    }

```

