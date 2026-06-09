### 解题思路
新建一链表，遍历那两链表，比较大小，写入新链表

### 代码

```java

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0),cur = res;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                cur.next = l1;
                l1 = l1.next;
            }else{
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        if(l1 = null){
            cur.next = l2;
        }else{
            cur.next = l1;
        }
        return res.next;
    }
}



```