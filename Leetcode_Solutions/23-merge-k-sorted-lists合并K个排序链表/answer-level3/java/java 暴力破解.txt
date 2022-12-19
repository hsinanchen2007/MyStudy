### 解题思路
将每两个链表进行合并操作，再与其他链表进行合并操作。

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
        if (lists.length == 0 ){
            return null;
        }
        //两个链表两个链表的合并。
        ListNode start = lists[0];
        for(int i=1;i<lists.length;i++){
            start = mergeKList(start,lists[i]);
        }
        return start;
    }

    public ListNode mergeKList(ListNode list1, ListNode list2){
        ListNode result = new ListNode(0);
        ListNode res = result;
        // int cur == 0;
        //判断两个都有的时候
        while (list1 !=null && list2 != null){
            if (list1.val > list2.val){
                res.next = list2;
                res = res.next;
                list2 = list2.next;
            }else if(list1.val <= list2.val){
                res.next = list1;
                res = res.next;
                list1 = list1.next;
            }
            
        }
        // 当只有list1存在的时候
        while(list1 != null){
            // System.out.println(list1.val);
            res.next = list1;
            res = res.next;
            list1 = list1.next;
        }
        while(list2 != null){
            res.next = list2;
            res = res.next;
            list2 = list2.next;
        }
        return result.next;

    }
}
```