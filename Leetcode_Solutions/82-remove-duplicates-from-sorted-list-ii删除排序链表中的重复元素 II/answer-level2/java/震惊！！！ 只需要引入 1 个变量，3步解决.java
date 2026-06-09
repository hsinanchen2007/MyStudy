### 解题思路
1. 全局引入当前重复的值 repeatNum , head 值如果重复，则 head = next

举个比方 [1,1,1,2,2,3]
1. repeatNum = 1 ,  当前 next 指向最后一个 1   [1,1,2,2,3]
2. head == next == repeatNum ,  head 不能为 repeatNum , head = next , 重新赋值
3. 重新计算 next , 当前 next 指向 2  [2,2,3]
4. next == next.next , 所以 next 指向 3  [3]
5. head = next , 输出 [3]


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private int repeatNum = Integer.MAX_VALUE;

    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }

        // 1. 递归中获取正确的 next
        head.next = deleteDuplicates(head.next);

        // 2. head 值等于 next ， 标记 repeatNum
        if(head != null && head.next != null && head.val == head.next.val){
            repeatNum = head.val;
        }

        // 3. head 值为 repeatNum 一律跳过
        while(repeatNum != Integer.MAX_VALUE && head != null && head.val == repeatNum){
            head = head.next;
        }

        return head;

    }
}
```