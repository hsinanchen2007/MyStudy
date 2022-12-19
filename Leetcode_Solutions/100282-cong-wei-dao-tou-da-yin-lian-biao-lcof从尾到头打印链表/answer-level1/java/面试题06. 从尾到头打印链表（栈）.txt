### 解题思路
栈方法，先进后出

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
        Stack<Integer> stack=new Stack<Integer>();
        while(head!=null){
            stack.push(head.val);
            head=head.next;
        }
        int l=stack.size();
        int[] res=new int[l];
        for(int i=0;i<l;i++){
            res[i]=stack.pop();
        }
        return res;
    }
}
```