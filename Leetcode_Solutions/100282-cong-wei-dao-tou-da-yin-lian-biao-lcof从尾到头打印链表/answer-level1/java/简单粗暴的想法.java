### 解题思路
链表就用数组存就完事了。

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
    public int[] reversePrint(ListNode head) {
        ListNode p=head;
        if(p==null){
            return new int[0];
        }
        int l=0;
        int[] ans=new int[10000];
        while(p.next!=null){
            ans[l]=p.val;
            p=p.next;
            l++;
        }
        ans[l]=p.val;
        int[] a=new int[l+1];
        for(int i=0;i<=l;i++){
            a[i]=ans[l-i];
        }
        return a;
    }
}
```