### 解题思路
递归其实就是找到退出条件+预处理+递归+后处理
此题的退出条件，就是l1，l2的val为空以及进位量(plus)为0时

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 递归
        return recur(new ListNode(0),l1,l2,0).next;
    }

    public ListNode recur(ListNode res,ListNode l1, ListNode l2,int plus){
         // stop 条件
        if (l1 == null && l2 == null && plus == 0){
            return null;
        }

        // 处理
        int result = (l1==null ? 0:l1.val) + (l2 == null ? 0:l2.val) + plus;
        int val = result % 10;

        res.next = new ListNode(val);

        // 递归
        recur(res.next,l1 == null ? l1 : l1.next,l2 == null ? l2 : l2.next,result / 10);

        return res;
    }
}
```