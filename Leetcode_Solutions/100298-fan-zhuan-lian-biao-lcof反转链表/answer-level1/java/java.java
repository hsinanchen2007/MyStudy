### 解题思路
首先是暴力的放入栈中，遍历解决。第二种就是双指针，其中注意java指针的值和传递性

### 代码

class Solution {
    public ListNode reverseList(ListNode head) {
        Stack<ListNode> nodeStack= new Stack<ListNode>();
        while(head!=null){
            ListNode temp = head;
            head = head.next;
            temp.next = null;
            nodeStack.push(temp);
        }
        ListNode useless =  new ListNode(-1);
        ListNode uselessHead = useless;
        while(!nodeStack.isEmpty()){
            useless.next = nodeStack.pop();
            useless = useless.next;
        }
        return uselessHead.next;

    }
}

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
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next == null){
            return head;
        }
        ListNode pre = null;
        ListNode cur = head;
        while(cur!=null){
            ListNode tempCur = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tempCur;
        }
        return pre;
    }
}
```