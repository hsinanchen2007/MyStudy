### 解题思路
此处撰写解题思路

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
        int res=0;
        ListNode temp=head;
        while(temp!=null){
            res=res*2+temp.val;//关键，在前一个res基础上乘二等于前面二进制都往前移了一格
            temp=temp.next;
        }
        return res;
    }
}
```