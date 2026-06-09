### 解题思路
借鉴归并思路。

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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0){
            return null;
        }
        return solution(lists,0,lists.length-1);
    }

    private ListNode solution(ListNode[] lists,int l,int r){
        if(l >= r){
            return lists[l];
        }
        int m = l + (r-l)/2;
        ListNode left = solution(lists,l,m);
        ListNode right = solution(lists,m+1,r);
        return merge(left,right);
    }

    private ListNode merge(ListNode left,ListNode right){
        ListNode temp = new ListNode(-1);
        ListNode root = temp;
        ListNode l = left;
        ListNode r = right;
        while(l != null && r != null){
            if(l.val > r.val){
                temp.next = r;
                r = r.next;
                temp = temp.next;
            }else{
                temp.next = l;
                l = l.next;
                temp = temp.next;
            }
        }
        while(l != null){
            temp.next = l;
            temp = temp.next;
            l = l.next;
        }
        while(r != null){
            temp.next = r;
            temp = temp.next;
            r = r.next;
        }
        return root.next;
    }
}
```