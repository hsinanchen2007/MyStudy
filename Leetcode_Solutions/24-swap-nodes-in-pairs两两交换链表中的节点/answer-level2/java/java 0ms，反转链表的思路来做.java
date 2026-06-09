### 解题思路
整体思路，以反转链表的思路来做，方法：双指针法
1.定义一个头结点，因为要进行前两个要进行交换，因此头结点的下一个为开始结点
dummy.next = head.next；
2.定义快慢指针，同时在while循环中保留fast.next，留作备用
3.以反转链表的方式，反转前两个结点
4.正常往下进行，直到最后区分剩下一个还是零个非空结点，一个时，fast为空，循环结束
slow指向最后一个非空，零个结点时结点时slow指向空结点，结束
### 代码

```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head.next;
        ListNode slow = head;
        ListNode fast = head.next;
        while(slow!=null && fast!=null){
            ListNode nextTemp = fast.next;
            fast.next = slow;
            if(nextTemp!= null && nextTemp.next!=null)
                slow.next = nextTemp.next;
            else 
                slow.next = nextTemp;
            slow = nextTemp;
            if(nextTemp!= null){
                fast = nextTemp.next;
            }                
        }
        return dummy.next;
    }
}
```