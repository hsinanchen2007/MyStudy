### 解题思路
1.遍历一遍，计算结点数。2.通过count，给数组赋相应的值。时间复杂度O(n)

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
        int count=0;
        ListNode temp = head;
        while(temp!=null){
            count++;
            temp = temp.next;
        }
        int[] ans = new int[count];
        int j=count-1;;
        while(head!=null){
            ans[j] = head.val;
            head = head.next;
            j--;
        }
        return ans;

    }
}
```