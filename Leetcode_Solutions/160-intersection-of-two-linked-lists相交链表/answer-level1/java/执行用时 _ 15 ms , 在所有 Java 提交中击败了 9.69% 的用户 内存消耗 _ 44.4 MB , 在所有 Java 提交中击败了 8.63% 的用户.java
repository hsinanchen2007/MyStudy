### 解题思路
一般般的方法，但是好理解，针对A和B链表，我们首先使用Set集合存储A中的每一个指针域，并在存储完毕后开始遍历B链表，看B中的指针是否存在于set集合中，如果存在，立刻返回该指针，如果遍历完毕依然不包含，我们只能说A和B没有共同交集指针，返回Null，代码也很简洁

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
        ListNode A = headA;
        ListNode B = headB;
        Set<ListNode> set = new HashSet<ListNode>();
        while(A!=null) {
            set.add(A);
            A = A.next;
        }
        while(B!=null) {
            if(set.contains(B)) {
                return B;
            }else {
                B = B.next;
            }
        }
        return null;
    }
}
```