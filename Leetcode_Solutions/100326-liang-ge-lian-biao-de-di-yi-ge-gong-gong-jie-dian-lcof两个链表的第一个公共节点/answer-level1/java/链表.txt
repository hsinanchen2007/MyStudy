### 解题思路
参看官方题解思路；  
len1 + len2 == len2 + len1的；所以当我们完成第一个遍历完毕之后，再去遍历第二个。第二个也同样，遍历完成之后再去遍历第一个。这样他们都是会一起到达最后一个点。也会从开始香蕉的第一个点一起到达第二个点的。所以这就是我们的解题关键。

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
        if(headA == null || headB == null)
            return null;
        ListNode tailA = headA;
        ListNode tailB = headB;
        int count = 0;
        while(true){
            if(tailA == null){
                tailA = headB;
                count += 1;
            }
            if(tailB == null){
                tailB = headA;
                count += 1;
            }
            // System.out.println("tailA.val = " + tailA.val + "; tailB.val = " + tailB.val);
            if(tailA == tailB){
                return tailA;
            }
            tailA = tailA.next;
            tailB = tailB.next;
            if(count > 2)
                break;
        }
        return null;
    }
}
```