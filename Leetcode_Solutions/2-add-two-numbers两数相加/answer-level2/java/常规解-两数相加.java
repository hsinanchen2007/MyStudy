### 解题思路
此处撰写解题思路
需要考虑几个点：
1.需要考虑满10 进 1 ，最后保留下来的值。
2.边界值情况，链表长度相同，最后相加 进入1 ，需要多加一位。
3.链表长度不同的情况
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode root = new ListNode();
        ListNode tmp = root;
        int addone = 0;
        for(;;){
            int val1 = l1 == null?0:l1.val ;
            int val2 = l2 == null?0:l2.val;
            int sum = val1 + val2+addone;
            addone =  sum>=10?1:0;
            sum = sum >=10?sum -10:sum;
            tmp.val = sum;
            System.out.println(sum);
            l1 = l1 == null ?null:l1.next;
            l2 = l2==null?null:l2.next;
            if (l1 ==null && l2==null){
                 if (addone > 0){
                    tmp.next = new ListNode(1);
                } 
                break;
            }
            tmp.next = new ListNode(0);
            tmp = tmp.next;
        }
        return root;

    }
}
```