先算出两个链表的长度，如果一样长，就可以同时遍历，然后逐一比较。如果一长一短，就先遍历长的，直到两个链表剩下的一样长，然后同时遍历，逐一比较。

![image.png](https://pic.leetcode-cn.com/84b75db99db370fabe27ca963f280a042eb2ddd2784a9bdf0561af78b12726f4-image.png)


代码如下：

```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode h1 = headA;
        ListNode h2 = headB;
        int length1 = 0;
        int length2 = 0;
        //获取链表headA的长度
        while(headA != null ) {
            length1 ++;
            headA = headA.next;
        }
        //获取链表headB的长度
        while(headB != null ) {
            length2 ++;
            headB = headB.next;
        }

        if(length1 > length2) {
            int dis = length1 -length2;
            while (dis > 0) {
                h1 = h1.next;
                dis --;
            }
            while (h1 != null) {
                if(h1 == h2) {
                    return h1;
                } else {
                    h1 = h1.next;
                    h2 = h2.next;
                }
            }
            return null;
        } else {
            int dis = length2 -length1;
            while (dis > 0) {
                h2 = h2.next;
                dis --;
            }    
            while (h1 != null) {
                if (h1 == h2) {
                    return h1;
                } else {
                    h1 = h1.next;
                    h2 = h2.next;
                }
            }
            return null;
        }
    }
}
```
