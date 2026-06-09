### 解题思路
没啥好写的，但是真的要吐槽一下，同一个代码一次20%，一次93%，跑了以下最牛代码，居然更慢，不知道是不是增加了测试组之前的代码。
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
    public int GetDecimalValue(ListNode head) {
                    List<int> ll = new List<int>();

            while (head != null)
            {
                ll.Add(head.val);
                head = head.next;
            }

            int result = 0;
            int bit = 0;
            for (int i = ll.Count - 1; i >= 0; i--)
            {
                if (ll[i] == 1)
                {
                    result += (int)Math.Pow(2, ll.Count - i - 1);
                }
            }
            return result;
            res = 0;
        
        }
}
```