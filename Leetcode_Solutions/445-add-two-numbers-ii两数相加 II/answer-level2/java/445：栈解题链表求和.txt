## 思想：
题目要求不翻转链表，利用栈先进后出的思想。将两个栈顶弹出的元素相加。
## 踩得一些坑
1. java实现中栈是整型，但是我把链表ListNode类型结点放入栈中，类型不同报错。应当push ListNode.val。
2. 两个整数相加还要考虑到进位，比如十位数相加要考虑到个位的进位。同时也要看看十位数相加会不会产生进位生成百位。比如10+99的结果是三位数生成了百位。所以要对进位这个变量`jnwei`判断是否为0，如果两个栈都为空`jinwei!=0`的时候还是要进行求和操作。
3. 如果用js实现修改进位的时候要向下取整，因为`9/10==0.9!=0`,这点与JS不同。
4. 在循环内部也要对栈是否为空做出判断，空就加0，非空取栈顶元素
5. 在创建输出结果的链表时借助哑结点head。` nlist.next=head.next;`保证了当前的结点与上一个结点的连接，总之很妙，当时这里卡住了。
## java和js语言的代码
```
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
        Stack<Integer> stack1= new Stack<>();
        Stack<Integer> stack2= new Stack<>();
        while(l1!=null){
            stack1.push(l1.val);
            l1=l1.next;
        }
        while(l2!=null){
            stack2.push(l2.val);
            l2=l2.next;
        }
        int jinwei=0;
        ListNode head=new ListNode(0);
        while(!stack1.isEmpty()||!stack2.isEmpty()||jinwei!=0){
            int a=stack1.isEmpty()?0:stack1.pop();
            int b=stack2.isEmpty()?0:stack2.pop();
            int sum=(a+b+jinwei)%10;
            ListNode nlist= new ListNode(sum);
            nlist.next=head.next;//至关重要的一步
            head.next=nlist;
            jinwei=(a+b+jinwei)/10;


        }
        return head.next;
    }
}
```
```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
var stack1=[];
var stack2=[];
while(l1!=null){
    stack1.push(l1.val);
    l1=l1.next;
}
while(l2!=null){
    stack2.push(l2.val);
    l2=l2.next;
}
var jinwei=0;
var head=new ListNode(0);
while(stack2.length>0||stack1.length>0||jinwei!=0){
    var a=stack1.length==0?0:stack1.pop();
    var b=stack2.length==0?0:stack2.pop();
    var sum=a+b+jinwei;
    var node=new ListNode(sum%10);
    node.next=head.next;
    head.next=node;
    jinwei=Math.floor(sum/10); //之前没有向下取整，找bug找了一小时，，，
    //向下取整

}
return head.next;
};
```