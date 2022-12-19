### 解题思路
总结，多考虑位运算，提高效率

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
        List<Integer> list = new ArrayList<>();
        int result = 0;
        int times = 0;
        while (head != null){
            // list.add(head.val);
            // head = head.next;
            result = (result << 1) + head.val;
            head = head.next;
        }
        // for(int i = list.size() - 1; i >= 0; i--){
        //     result += Math.pow(2, times) * list.get(i);
        //     times += 1;
        // }
        return result;
    }
}
```