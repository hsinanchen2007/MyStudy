### 解题思路
方法一：反转链表，再将值依次放入数组中

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
        ListNode ret = new ListNode(0);
        ret.next = null;
        ListNode p = ret, q = head;
        int count = 0;
        while(q != null){
            p = q;
            q = q.next;
            p.next = ret.next;
            ret.next = p;
            count++;
        }

        int[] res = new int[count];
        for(int i = 0; i <count; i++){
            ret = ret.next;
            res[i] = ret.val;}
        return res;
    }
}
```
方法二：利用栈，将链表值依次push()进栈，再依次pop()取出来放进数组中
```java
class Solution {
    public int[] reversePrint(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        while(head != null){
            stack.push(head.val);
            head = head.next;
        }
        int[] ret = new int[stack.size()];
        int i = 0;
        while(!stack.empty()){
            ret[i++] = stack.pop();
        }
        return ret;
    }
}
```

方法三：利用递归方法进行调用，在回溯过程中依次将元素放入数组中
```java

class Solution {
    public int[] reversePrint(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        recursion(list, head);
        int[] ret = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            ret[i] = list.get(i);
        }
        return ret;
    }
    public void recursion(ArrayList<Integer> list, ListNode head){
        if(head == null) return;
        recursion(list, head.next);
        list.add(head.val);
    }
}
```