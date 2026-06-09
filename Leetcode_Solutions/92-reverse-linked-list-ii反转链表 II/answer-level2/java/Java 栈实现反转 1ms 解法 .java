### 解题思路
分三步构建
1、反转链表之前的前缀链表
2、反转链表
3、反转链表之后的后缀链表

从头结点遍历 根据索引值构建
反转链表用“先进后出”的栈实现。
将三部分链接即可

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
    private ListNode rev_head = new ListNode(0);//需要反转的哑节点头
    private ListNode rev = rev_head;

    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode preNode_head = new ListNode(0);//前缀链表头部
        ListNode preNode = preNode_head;
        ListNode afNode_head = new ListNode(0);//后缀链表头部
        ListNode afNode = afNode_head;
        Stack<ListNode> reverseNode = new Stack<>();//用栈存储需要反转的节点
        int index = 1;
        while (head != null){
            //索引在反转的起点前 则构建前缀链表
            if (index < m){
                preNode.next = new ListNode(head.val);
                preNode = preNode.next;
            }
            //索引处于反转的起点和终点之间 将节点放入栈中
            if (index >= m && index <= n){
                reverseNode.push(head);
            }
            //索引在反转的终点之后 构建后缀链表
            if (index > n){
                afNode.next = new ListNode(head.val);
                afNode = afNode.next;
            }
            index++;
            head = head.next;
        }
        buildRevNode(reverseNode);//构建反转链表

        //最终结果为前缀链表+反转链表+后缀链表（注意三个的头结点都是哑结点）
        preNode.next = rev_head.next;
        if (rev != null) {
            rev.next = afNode_head.next;
        }
        return preNode_head.next;
    }

    private void buildRevNode(Stack<ListNode> stack){
        while (!stack.isEmpty()){
            rev.next = new ListNode(stack.pop().val);
            rev = rev.next;
        }
    }
}
```