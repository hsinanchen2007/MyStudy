### 解题思路
从前往后遍历，复杂度O(n)

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
    public int kthToLast(ListNode head, int k) {
        //第一步：判断能不能返回
        ListNode p=head;
        int count=0;
        while(p!=null)
        {
            count++;  p=p.next;
        }
        if(k>count)
            return -1;
        else if(k==count)
            return head.val;
        else
        {
            int x=count-k;
            while(x>0)
            {
                head=head.next;
                x--;
            }
            return head.val;
        }
    }
}
```