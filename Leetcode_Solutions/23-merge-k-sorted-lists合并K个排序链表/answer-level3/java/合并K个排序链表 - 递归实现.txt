**递归实现**，很简单
思路：遍历访问K个链表的头节点，得到最小值节点，把这个节点下移一位,将最小值节点的next指向下一个递归方法，再返回最小值节点。当所有链表都为null时，返回null。
Java代码实现如下：
```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int minv = Integer.MAX_VALUE;
        int mini = -1;
        for(int i = 0; i < lists.length; i++) {
            if(lists[i] != null && lists[i].val <= minv) {
                minv = lists[i].val;
                mini = i;
            }
        }
        if(mini == -1)
            return null;
        else {
            ListNode tmp = lists[mini];
            lists[mini] = lists[mini].next;
            tmp.next = mergeKLists(lists);
            return tmp;
        }
    }
}
```
**复杂度分析**
时间复杂度：O(kN), N为总的节点个数。

*第一次写题解，请见谅*
