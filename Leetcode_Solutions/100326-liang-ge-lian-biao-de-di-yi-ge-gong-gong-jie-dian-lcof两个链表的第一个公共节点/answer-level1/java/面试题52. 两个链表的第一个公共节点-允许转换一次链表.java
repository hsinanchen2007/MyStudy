### 解题思路

当A到尾部的时候，切换到B的头部，当B到尾部的时候，切换到A的头部

当然，A 和 B 各自都只允许切换一次(无限次可能导致死循环。。)

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode currentA = headA;
        ListNode currentB = headB;
        int exchangeNumA = 0;
        int exchangeNumB = 0;

        while(currentA != null && currentB != null){
            if(currentA.equals(currentB)){
                return currentA;
            }

            currentA = currentA.next;
            if(currentA == null && exchangeNumA < 1){
                exchangeNumA ++;
                currentA = headB;
            }

            currentB = currentB.next;
            if(currentB == null && exchangeNumB < 1){
                exchangeNumB ++;
                currentB = headA;
            }
        }

        return null;
        
    }
}
```