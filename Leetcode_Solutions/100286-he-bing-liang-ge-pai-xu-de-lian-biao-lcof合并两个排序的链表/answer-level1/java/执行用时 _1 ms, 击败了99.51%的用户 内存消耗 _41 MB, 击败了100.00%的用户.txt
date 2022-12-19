### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了99.51%的用户
内存消耗 :41 MB, 在所有 Java 提交中击败了100.00%的用户

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null){
            return l2;
        }else if(l2 == null){
            return l1;
        }

        ListNode res;
        if (l1.val <= l2.val){
            res = l1;
            l1 = l1.next;
        }else{
            res = l2;
            l2 = l2.next;
        }

        ListNode temp = res;


        while (true){
            if (l1 == null){
                temp.next = l2;
                return res;
            }else if(l2 == null){
                temp.next = l1;
                return res;
            }

            if (l1.val <= l2.val){
                temp.next = l1;
                l1 = l1.next;
                temp = temp.next;
                // if (l1 == null){
                //     temp.next = l2;
                //     return res;
                // }
            }else{
                temp.next = l2;
                l2 = l2.next;
                temp = temp.next;
                // if (l2 == null){
                //     temp.next = l1;
                //     return res;
                // }
            }
        }
    }
}
```