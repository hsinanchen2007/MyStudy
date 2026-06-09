### 解题思路
1. 相同下标的2个数相加（null的值记录为0），结果为num
2. 记录下次操作的位数（需要进1、进2...），为：num / 10
3. 记录当前相加结果：num % 10
4. 依次递归下去
#### 注意，数据的边界为：
1. 下次操作的位数为0，并且下标都为0
#### 为了提升性能
1. 仅有一个链表有值，并且下次操作的位数为0时
2. 将next.next直接指向链表.next
3. 不需要继续递归
#### 时间复杂度：O(min(l1.size, l2.size))

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
        ListNode res = new ListNode(0);
        add(res, l1, l2, 0);
        return res.next;
    }

    private void add(ListNode res, ListNode l1, ListNode l2, int add) {
        if (add == 0 && l1 == null && l2 == null) {
            return;
        }
        int n1 = 0, n2 = 0;
        if(l1 != null) {
            n1 = l1.val;
        }
        if (l2 != null) {
            n2 = l2.val;
        }
        int num = n1 + n2 + add;
        int newAdd = 0, div = num/10;
        if (div > 0) {
            newAdd = div;
            num -= newAdd * 10;
        }
        res.next = new ListNode(num);
        if (newAdd == 0 && ((l1 != null && l2 == null) || (l1 == null && l2 != null))) {
            res.next.next = (l1 != null ? l1.next : l2.next);
            return;
        }
        add(res.next, l1 != null ? l1.next : null, l2 != null ? l2.next : null, newAdd);
    }
    
    
}
```