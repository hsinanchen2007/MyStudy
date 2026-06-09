### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
34.4 MB
, 在所有 java 提交中击败了
100.00%
的用户

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
    public int getDecimalValue(ListNode head) {
                int res=-1;
        String binary_num=String.valueOf(head.val);
        ListNode t=head;
        while(t.next!=null){
            t=t.next;
            binary_num+=String.valueOf(t.val);
        }
        res=Integer.parseInt(binary_num,2);
        return res;
        
    }
}
```