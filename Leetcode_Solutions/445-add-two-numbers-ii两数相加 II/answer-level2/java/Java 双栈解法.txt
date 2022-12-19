### 解题思路
此处撰写解题思路
1. Java 采用 ArrayDeque 来模拟栈这种数据结构
2. 双栈 解法 注意 最后返回的List 是从高位到低位的
### 代码

```java
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
        ArrayDeque<Integer> stack1=new ArrayDeque<>();
        ArrayDeque<Integer> stack2=new ArrayDeque<>();
        while(l1!=null){
         stack1.push(l1.val);
         l1=l1.next;
        }
        while(l2!=null){
            stack2.push(l2.val);
            l2=l2.next;
        }
        int carry=0;
        ListNode tail=new ListNode(0);
        ListNode p=tail,q=tail;
        while(!stack1.isEmpty()||!stack2.isEmpty())
        {   int x=0,y=0;
            if(!stack1.isEmpty())x=stack1.pop();
            if(!stack2.isEmpty())y=stack2.pop();
            q.val=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            p=new ListNode(0);
            p.next=q;
            q=p;
        }
        if(carry>0) {q.val=1; return q;}
        return q.next;

    
        
    }
}
```