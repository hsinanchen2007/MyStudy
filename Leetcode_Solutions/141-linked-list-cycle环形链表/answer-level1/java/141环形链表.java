### 解法一（哈希表）

遍历链表的时候只要判断链表种包含相同的元素即代表链表有环，
注意比较的是ListNode，而不是val

所以只需要使用一个Set保存已遍历的元素即可

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet();
        while(head != null){
            if(set.contains(head)){
                return true;
            }else{
                set.add(head);
            }
            head = head.next;
        }
        return false;
    }
}
```

### 复杂度分析

只需遍历一遍，所以时间复杂度是O(n)
空间复杂度为O(n)


---

### 解法二（快慢指针）

参考龟兔赛跑，只要跑道有环，它们总能在跑道中间遇到。
这个确实不容易想到

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow) return true;
        }
        return false;
    }
}
```

### 时间复杂度为O(n)

