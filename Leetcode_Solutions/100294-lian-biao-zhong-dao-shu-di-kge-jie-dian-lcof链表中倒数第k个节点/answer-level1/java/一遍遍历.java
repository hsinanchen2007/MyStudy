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
    public ListNode getKthFromEnd(ListNode head, int k) {

        ListNode tmp = head;
        ListNode res = head;
        int count = 0;
        while(tmp != null){
            tmp = tmp.next;
            count++;
            if(count > k)
                res = res.next;
        }
        return res;
    }
}
```
一遍遍历，记录到k值后，res和tmp同步后移。