```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/** 解法一：此题返回值为int[]，有区别于其它平台题的ArrayList[]以及ListNode
 * 先遍历一遍链表记录长度，然后遍历链表倒序将val值存入数组（感觉不是题目的本意）
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        int[] res = new int[0];
        if(head==null){
            return res;
        }
        int index = 0;
        ListNode node = head;
        while (node!=null){
            index++;
            node = node.next;
        }
        res = new int[index];
        while (head!=null){
            res[--index]=head.val;
            head = head.next;
        }
        return res;
    }
}
```

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.Stack;

/**
 * 解法二：利用辅助栈
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        int[] res = new int[0];
        if(head==null){
            return res;
        }
        Stack<ListNode> stack = new Stack<>();
        while (head!=null){
            stack.push(head);
            head = head.next;
        }
        res = new int[stack.size()];
        int i=0;
        while (!stack.isEmpty()){
            res[i++] = stack.pop().val;
        }
        return res;
    }
}
```

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/**
 * 解法三 递归法
 */
class Solution {
    private int[] res = new int[0];
    private int index = 0;
    public int[] reversePrint(ListNode head) {
        if(head==null){
            return res;
        }
        reverse(head);
        return res;
    }

    private void reverse(ListNode node) {
        if(node==null){
            return;
        }
        index++;
        if(node.next!=null){
            reverse(node.next);
        }
        if(res.length==0){
            res= new int[index];
            index=0;
        }
        res[index++]=node.val;
    }
}
```