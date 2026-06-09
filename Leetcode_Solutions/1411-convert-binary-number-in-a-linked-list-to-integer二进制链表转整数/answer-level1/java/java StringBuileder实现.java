### 解题思路
先把链表值存入StringBuilder，然后遍历StringBuilder，转换成十进制。

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
        StringBuilder sb = new StringBuilder();
        int sum = 0;
        while(head != null){
            sb.append(head.val);
            head = head.next;
        }
        for(int i = 0;i<sb.length();i++){
            if(sb.charAt(i) == '1'){
                sum += Math.pow(2,sb.length()-i-1);
            }
            
        }
        return sum;
    }
}
```