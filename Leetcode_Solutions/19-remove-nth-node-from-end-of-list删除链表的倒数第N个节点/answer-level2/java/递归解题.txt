    
直接上代码：

```
public static ListNode listNodeTmp;

public ListNode removeNthFromEnd(ListNode head, int n) {
    listNodeTmp = null;
    if(head == null){
        return head;
    }
    int num = nodeNum(head,n);
    if(num == n){
        return head.next;
    }
    return head;
}
public int nodeNum(ListNode head,int n){
    int tmp = 0;
    if(head != null){
        tmp = 1+ nodeNum(head.next,n);
        if(tmp == n +1){
            head.next = listNodeTmp;
        }
        if(tmp == n-1){
            listNodeTmp = head;
        }
    }
    return tmp;
}
```
