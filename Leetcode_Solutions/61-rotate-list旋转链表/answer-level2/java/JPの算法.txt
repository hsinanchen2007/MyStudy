微博：@带带大师兄

思路：先遍历一次链表获取元素个数，然后操作快慢指针，快指针到达结尾时，快指针的下一个指向头节点，头节点指向慢指针的下一个，慢指针的下一个指向null

![image.png](https://pic.leetcode-cn.com/37abccb9b258ab582ea747710155110bc1fc1f7b95758dd923d660732fc02f57-image.png)

```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||k==0)
            return head;
        ListNode tmp = head;
        int len = 1;
        while(tmp!=null&&tmp.next!=null){
            tmp = tmp.next;
            len++;
        }
        k = k%len;

        ListNode first = head;
        ListNode second = head;
        for(int i=0;i<k;i++){
            second = second.next;
        }
        while(second!=null&&second.next!=null){
            first = first.next;
            second = second.next;
        }
        second.next = head;
        head = first.next;
        first.next = null;
        return head;
    }
}
```
