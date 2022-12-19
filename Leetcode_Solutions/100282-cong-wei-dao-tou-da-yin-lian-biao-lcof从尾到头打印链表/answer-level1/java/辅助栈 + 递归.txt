### 解题思路
# **辅助栈法**
从头遍历链表，将只加入栈，然后从栈取出的序列就是从尾到头打印的结果；
# **递归法**
1. 明确函数功能int[] reversePrint(ListNode head)就是倒序打印链表，那么给定一个头结点，返回值就是倒序的数组！！！这一点要明确！！
2. 明确递归体：加入有个链表，头结点之后都已经被倒序打印出来了，那么只要将头结点的值加到倒序打印的尾部即可！！
```
        int[] printed = reversePrint(head.next);
        int[] ans = new int[printed.length + 1];
        for(int i = 0; i < printed.length; i++){
            ans[i] = printed[i];
        }
        ans[printed.length] = head.val;
```
3. 明确递归终止条件：头结点为空，返回空数组

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
        /*辅助栈法
        Deque<Integer> stack = new LinkedList<Integer>();
        while(head != null){
            stack.offerLast(head.val);
            head = head.next;
        }
        int n = stack.size();
        int[] ans = new int[n];
        int i = 0;
        while(i < n){
            ans[i++] = stack.pollLast();
        }
        return ans;
        */
        //递归法
        if(head == null){
            return new int[]{};
        }
        int[] printed = reversePrint(head.next);
        int[] ans = new int[printed.length + 1];
        for(int i = 0; i < printed.length; i++){
            ans[i] = printed[i];
        }
        ans[printed.length] = head.val;
        return ans;
    }
}
```