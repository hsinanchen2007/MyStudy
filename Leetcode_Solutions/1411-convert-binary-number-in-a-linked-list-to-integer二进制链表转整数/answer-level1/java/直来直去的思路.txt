### 解题思路
1.得到二进制string
2.将string转化为十进制

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
        if (head == null) {
            return 0;
        }
        StringBuffer stringBuffer = new StringBuffer();
        while (head != null) {
            stringBuffer.append(head.val);
            head = head.next;
        }
        int result = Integer.valueOf(stringBuffer.toString(), 2);
        return result;
    }
}
```