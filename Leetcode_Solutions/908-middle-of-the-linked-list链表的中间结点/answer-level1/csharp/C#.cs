### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    /// <summary>
    /// 方法一：快慢指针
    /// </summary>
    public ListNode MiddleNode1(ListNode head) {
        ListNode ans = head;
        ListNode n = head;
        int count = 0;
        while(n != null)
        {
            if(count == 0)
            {
                count++;
            }
            else
            {
                ans = ans.next;
                count--;
            }
            n = n.next;
        }
        return ans;
    }

    /// <summary>
    /// 方法二：数组
    /// </summary>
    public ListNode MiddleNode2(ListNode head) {
        List<ListNode> list = new List<ListNode>();
        ListNode n = head;
        do
        {
            list.Add(n);
            n = n.next;
        }
        while(n != null);
        return list[list.Count / 2];
    }
}
```


