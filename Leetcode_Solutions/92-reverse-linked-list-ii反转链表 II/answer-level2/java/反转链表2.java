*执行用时 :1 ms, 在所有 Java 提交中击败了84.17%的用户
内存消耗 :34.4 MB, 在所有 Java 提交中击败了81.92%的用户*

# 解法就是双指针，pre和p， pre指向开始反转之前的结点，遍历p直到p指向第一个开始反转的位置，然后把p后面的结点插入到pre结点的后面；
```
  if (head == null || head.next == null){
            return head;
        }
        ListNode L = new ListNode(-1);
        L.next = head;
        ListNode tmp ;
        ListNode p = head;
        ListNode pre = L;
        int cnt = 1;
        while (p != null && cnt < n){
            if (cnt >= m){
                tmp = p.next;
                p.next = tmp.next;
                tmp.next = pre.next;
                pre.next = tmp;
            }else {
                pre = pre.next;
                p = p.next;
            }
            cnt++;
        }
        return L.next;
```
