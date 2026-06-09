### 解题思路
把两个链表分别压栈，取栈顶元素相加并判断是否需要进位，不需要的话直接创建节点使用头插法，需要进位的话使用一个变量进行标记，在下一轮循环中进行加1操作。当两个栈都空且不需要进位是相加操作结束，返回新栈即可。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //获取两个链表的栈
        Stack<Integer> l1Stack = buildStack(l1);
        Stack<Integer> l2Stack = buildStack(l2);
        //创建一个节点作为新链表的头结点
        ListNode head = new ListNode(0);
        //标志变量
        int flag = 0;
        //当两个栈全空且不需要进位时，完成运算
        while(!l1Stack.isEmpty() || !l2Stack.isEmpty() || flag != 0){
            //使用两个栈中其中一个元素作为进位符
            int x =  flag;
            if(!l1Stack.isEmpty()){
                 x += l1Stack.pop();
            }
            //获取另一个栈顶元素
            int y = 0;
            if(!l2Stack.isEmpty()){
                y = l2Stack.pop();
            }
            //二者相加
            int z = x + y;
            //判断是否需要进位
            if(z >= 10){
                flag = 1;
            }else{
                flag = 0;
            }
            //创建新的节点进行头插
            ListNode node = new ListNode(z%10);
            node.next = head.next;
            head.next = node;
        }
        return head.next;
    }
    //创建一个压栈方法，返回压好的栈
    private Stack<Integer> buildStack(ListNode l) {
    Stack<Integer> stack = new Stack<>();
    while (l != null) {
        stack.push(l.val);
        l = l.next;
    }
    return stack;
    }
}
```