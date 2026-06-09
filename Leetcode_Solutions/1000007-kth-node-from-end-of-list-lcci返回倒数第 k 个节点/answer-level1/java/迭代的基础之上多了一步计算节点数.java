### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1c231aa144eb954d51a0572039505aa1f851689d47344a76532a96c9e851ebaa-image.png)

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

        int sum =0;
        ListNode cur = head;
        for (;cur!=null;cur = cur.next)
            sum++;
        ListNode p = null;
        ListNode q = null;
        int count=0;
        while(head!=null){
            q = head.next;
            head.next = p;
            p = head;
            head = q;
            if (((sum-k+1) == (++count))) return p.val;
        }
        return 0;
    }
}
```