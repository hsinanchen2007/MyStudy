### 解题思路
先根据k的大小，找出右边最大能到的位置。以这个步长通过递归的方式获取结果。

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
    public int kthToLast(ListNode head, int k) {
        ListNode left = head;
        ListNode right = head;
        while(k-- > 0){
            right = right.next;
        }
        // 递归一下
        return findResult(left,right);
    }

    private int findResult(ListNode left,ListNode right){
        if(right == null){
            return left.val;
        }
        return findResult(left.next,right.next);
    }
}
```