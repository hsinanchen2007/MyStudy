### 解题思路

/*
1 -> 2 -> 3 -> 4 -> 5   m=2, n=4   
定义两个指针，左指针和右指针
左指针指向要翻转的第一个结点的前一个结点    即指向1
右指针指向要反转的最后一个结点的下一个结点  即指向5
翻转234后进行拼接
*/

### 代码

```java

class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n || head == null) return head;  //考虑特殊情况，保证鲁棒性

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode left = new ListNode(0);
        ListNode right = new ListNode(0);
        ListNode p = dummy;
        int count = 0;

        //查找要翻转的部分
        while(p != null){
            if(count == m-1) left = p;
            if(count == n){
                right = p.next;
                break;
            }
            count++;
            p = p.next;
        }
        p.next = null;    //注意找到要翻转的部分之后，要把最后一个结点的下一个结点置空

        //进行翻转
        ListNode rev = reverse(left.next);   
        
        //进行拼接
        left.next = rev;
        p = rev;
        while(p.next != null) p = p.next; 
        p.next = right;

        return dummy.next;
    }

    public ListNode reverse(ListNode head){
        if(head.next == null)  return head;

        ListNode res = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return res;
    }
}
```