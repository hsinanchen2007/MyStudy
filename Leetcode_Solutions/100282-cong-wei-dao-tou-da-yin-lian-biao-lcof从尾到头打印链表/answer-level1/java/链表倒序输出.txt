### 解题思路
利用栈的特点，把链表值顺序存入栈中，再出栈即可

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
        Stack<Integer> stack=new Stack();
        while(head!=null){
            stack.push(head.val);
            head=head.next;
        }
        int[] res=new int[stack.size()];
        int cnt=0;
        while(!stack.isEmpty()){
            res[cnt++]=stack.pop();
        }
        return res;
    }
}
```