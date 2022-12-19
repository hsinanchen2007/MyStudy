
**快慢指针**
快慢指针里面我们让慢指针走一步，快指针走2步。
首先要明白，两个指针怎么走的。快指针已经走完一个环，再加一小段或者0与慢指针相遇。


假设慢指针走到入环第一个要x，入环第一个到两指针重合的位置是y
而这时快指针走了，x+y+重合点到入环第一个的距离（设为z）+y

2*（x+y）=x+y+z+y
x = z
所以让一个指针回到原点，两个同时再走一遍，重合就到入环第一个了。

public class Solution {
 
    public ListNode detectCycle(ListNode head) {

        if(head==null||head.next==null) return null;
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null&&fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast) {
                slow = head;
                while(slow!=fast) {
                    slow = slow.next;
                    fast = fast.next;
            }
            return slow;    
            }
        }
        return null;

    }
}

**回环法**

while{
新建一个temp指向head后一个   
每次head。next = head （回环处理）
head = temp （向后移动）


if （head == head。next） return
//这里当我们遇到回环节点时，说明是我们处理过的节点，也就说明这个节点是环路的入口
}

下面是我写的，原理应该没错，方法原理详情看141，142
但提交不ac，于是我又看了playground调试，并没有什么和问题相关的。而且payground里居然自己有问题，solution里面如题有一个参数传进来，但main函数调用的时候给solution传了两个参数。

报错可能因为链表的结构不能改变，对比142链路回环有给出这个。
或者我真的写错了，希望有缘人看到指出。

public class Solution {
 
    public ListNode detectCycle(ListNode head) {

    while(head!=null&&head.next!=null) {
        ListNode temp = head.next;
        head.next = head;
        head = temp;
        if(head==head.next) return head;
    }
    return null;
    }
}