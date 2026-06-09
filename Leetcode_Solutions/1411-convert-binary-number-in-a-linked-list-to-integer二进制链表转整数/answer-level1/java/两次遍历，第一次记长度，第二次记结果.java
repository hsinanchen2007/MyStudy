### 解题思路
两次遍历，第一次记长度，第二次记结果

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
        int len=0;
        ListNode temp=head;
        while(temp.next !=null){
            len++;
            temp=temp.next;
        }
        temp=head;
        while(temp.next !=null){
            if(temp.val==1){
                 res+=Math.pow(2,len);
            }
            len--;
            temp=temp.next;
        }
        if(temp.val==1){
                 res+=Math.pow(2,len);
            }
        
        return res;
    }
}
```