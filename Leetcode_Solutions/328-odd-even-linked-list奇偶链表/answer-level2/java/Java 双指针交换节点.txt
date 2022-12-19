大致思路是:
    找到要交换的点, 用tmp记录, 然后将当前点移出链表(这个点的前一个连接这个点的后一个), 然后把tmp插入到上一个已交换的奇数点的后面


用一个结点odd记录上一个奇数点交换到了哪里
用一个count计数 判断当前位置是否奇数点
    若不是奇数点 用一个tmp结点记录当前位置便于下一个奇数点的交换
    如果是奇数点,就把这一个tmp插入到odd后面 将odd更新

```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        int count = 1;
        ListNode odd = head, now = odd.next, start = now;
        while(now != null) {
            count ++;
            if(count % 2 == 0) {
                start = now;
                now = now.next;
            }  else {
                ListNode tmp = now;
                now = now.next;
                start.next = now;
                tmp.next = odd.next;
                odd.next = tmp;
                odd = tmp;
            }
        }
        return head;
    }
}
```



