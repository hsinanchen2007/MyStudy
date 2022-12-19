### 解题思路
打卡+1
用两个指针一个临时变量，遍历反转

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
            ListNode pre = null;
            ListNode index = head;
            ListNode tmp = null;
            while(index!=null)
            {
                tmp = index.next;
                index.next=pre;
                pre=index;
                index=tmp;
            }
            return pre;
    }
}
```