### 解题思路


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

    class MergeLink
    {
        public ListNode MergeKLists(ListNode[] lists)
        {
            var DumpNode = new ListNode(-1);
            var curHead = DumpNode;
            var head = new List<ListNode>();
            foreach(var l in lists){
                head.Add(l);
            }
            while(head.Count > 0){
                var minI = -1;
                ListNode minHead = null;
                var minV = Int32.MaxValue;
                for (var i = 0; i < head.Count; i++){
                    if(head[i] != null && head[i].val < minV){
                        minV = head[i].val;
                        minHead = head[i];
                        minI = i;
                    }
                }
                if(minHead == null) break;
                curHead.next = minHead;
                curHead = minHead;
                if (minHead.next != null)
                {
                    head[minI] = minHead.next;
                }else {
                    head.RemoveAt(minI);
                }
            }

            return DumpNode.next;
        }
    }

public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        var ml = new MergeLink();
        return ml.MergeKLists(lists);
    }
}
```