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
    int num = 0;
    public int getDecimalValue(ListNode head) {
        int res = 0;
		
		if(head != null) {
			res += getDecimalValue(head.next);
			res += (head.val * Math.pow(2, num));
			num++;
		}
		
		return res;
    }
}
```