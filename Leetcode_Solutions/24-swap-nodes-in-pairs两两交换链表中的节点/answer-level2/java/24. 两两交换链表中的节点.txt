递归：两两交换
![image.png](https://pic.leetcode-cn.com/30d7cb51f8949534bad7452f97a602ce9c9b1722037ada0f7dbaab534e788b3d-image.png)



```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)return head;
        ListNode first = head;
        ListNode second = head.next;
        ListNode thir = second.next;
        second.next = first;
        first.next = swapPairs(thir);
        return second;
    }
}
```
