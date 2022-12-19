### 解题思路
先将元素放到列表中，然后再到列表中对首尾元素进行判断。

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
    public bool IsPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;

        List<int> value = new List<int>();
        ListNode curr = head;
        while(curr!=null){ value.Add(curr.val); curr = curr.next;}

        int i = 0, j = value.Count -1;
        while(i<=j)
        {
            if(value[i++] != value[j--]) return false;
        }

        return true;
    }
}
```