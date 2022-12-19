### 解题思路
使用归并的思路：将两个有序的子序列合并为一个有序的新序列，联想归并排序即可。

时间复杂度：O(n)。n为两链表长度之和。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(-1);
        ListNode temp = ans;
        while(l1 != null && l2 != null)
        {
            if(l1.val < l2.val)
            {
                temp.next = l1;
                l1 = l1.next;
            }
            else
            {
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        if(l1 == null)  temp.next = l2;
        else            temp.next = l1;
        return ans.next;
    }
}
```