//对数组循环赋值就可以
```
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
        int[] ans = new int[k];
        int tag = 0;
        while(head != null){
            ans[(tag++)%k] = head.val;
            head = head.next;
        }
        return ans[tag % k];
    }
}
```
