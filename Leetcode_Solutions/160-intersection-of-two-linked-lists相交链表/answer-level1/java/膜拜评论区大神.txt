### 解题思路
此处撰写解题思路
解题思路都是让两个指针同时开始遍历相同路径，即较长的链表需要先将长的路径走完。同样的思路，一开始写的代码很麻烦，需要比较长度，再让较长链表先走。参考了评论区大神的代码后，学会了下面的方法，膜拜

## 绝妙的解题思路
## 假设a链表长度为5，B链表长度为8
## 当pA为null时，B链表还剩3没走完，此时pA变成了headB，pB继续走
## 当pB走完时，pA在B链表上走了3，pB变成了headA，相当于两个指针开始走相同路径
## 那么while条件终止条件只能是，pA == pB，或者 pA == pB == null

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
        if(headA == null || headB == null){
            return null;
        }
        ListNode pA = headA;
        ListNode pB = headB;
        // 最后终止条件为pA和pB都为null
        while ( pA != pB){
            pA = pA == null? headB : pA.next;
            pB = pB == null? headA : pB.next;
        }
        return pA;
    }
}
```