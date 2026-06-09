### 解题思路
先来看看结果
    5，4，3，2，1
假设我们已经处理到curr=3了
显然1，2已经处理完了，并且我们清楚res=2，1
现在我们的问题是合并出3，2，1
我们做了两件事：1.将3指向res   2.将3，2，1作为新的res

坑：参照变量，谨慎赋值

### 代码

```csharp

public class Solution {
    public ListNode ReverseList(ListNode head) {
        return GetReverseList(head,null);

        ListNode GetReverseList (ListNode curr,ListNode res) {
            if (curr == null)   return res;
            ListNode newNode = new ListNode(curr.val);
            newNode.next = res;
            return GetReverseList(curr.next,newNode);
        }
    }
}
```