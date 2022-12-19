### 解题思路
链表a 为 [1,2,3,4,5];
链表b 为[0,3,4,5];
a+b = [**1,2,3,4,5**,0,3,4,5]
b+a = [0,3,4,5,**1,2,3,4,5**]
可以看到这样2个俩表的 长度就一样了。只要按照重头向后比找到相同的点就我们要的相交的点;
当然如果我们不是用额外的内存 我们只要使用2个指针分别从headA和headB开始往下对比，A走到最后回到B的头指针，B走到最后回到A模拟将ab拼接和ba拼接;


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode hA = headA, hB = headB;
        while (hA != hB) {
            hA = hA == null ? headB : hA.next;
            hB = hB == null ? headA : hB.next;
        }
        return hA;
    }
}
```