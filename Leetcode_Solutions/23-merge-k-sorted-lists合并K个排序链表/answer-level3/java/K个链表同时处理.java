### 解题思路
由于一开始没有想到堆，想法就是每次将当前lists里最小的节点lists[i]添加到结果，然后让lists[i]=lists[i].next,直到lists全部为空

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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0){
            return null;
        }

        ListNode res = new ListNode(0);
        ListNode pos = res;
        while (true){
            int min = Integer.MAX_VALUE;
            int idx = 0;
            int isEmpty = 0;
            for (int i = 0; i < lists.length; i++) {

                if (lists[i]==null) {
                    isEmpty++;
                    //退出while循环条件：所有项都为空
                    if (isEmpty == lists.length){
                        return res.next;
                    }
                    continue;
                }

                if (lists[i].val < min){
                    min = lists[i].val;
                    idx = i;
                }
            }
            pos.next = lists[idx];
            lists[idx] = lists[idx].next;
            pos = pos.next;
        }
    }
}
```