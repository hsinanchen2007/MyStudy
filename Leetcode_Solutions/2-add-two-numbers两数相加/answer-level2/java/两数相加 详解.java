分析：
在看到题的时候不要立刻写代码，需要仔细分析他的结构和边界的分析。
一、链表的结构相同
    1、两个链表对应的值之和没有超出9：
        1:>结果的链表相对应节点的值为两个链表对应值之和
    2、两个链表对应的值之和超出9:
        1:>链表中间相互节点和超出9，结果链表在该节点的值为（和取余数），然后下一个节点的值要加1，然后在判断是否在超9
        2:>链表结尾之和超出9，结果链表在该节点的值为（和取余数），然后需增加一个节点值为1
二、链表的结构不同
    1、两个链表的对应值之和没有超出9:
        1:>没有超出长度的链表的操作和上面（1:>）一样,超出部分直接在放在结果链表中
    2、两个链表的对应值之和超出9：
        1:>链表中间相互节点和超出9，结果链表在该节点的值为（和取余数），然后下一个节点的值要加1，然后在判断是否在超9
        2:>链表结尾之和超出9，结果链表在该节点的值为（和取余数），然后需对应链表一个节点值加1，且还需判断。例如（9+1）

代码如下：
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //头指针
        ListNode head = null;
        //为指针
        ListNode lastNode = null;
        //用户记录超出9的标记
        int temp = 0;
        //指针
        ListNode p = l1;
        ListNode q = l2;
        //将相同的位数进行相加
        while(p != null && q != null){
            //对应指针的值相加
            int val = p.val + q.val + temp;
            //新增的节点
            ListNode resultNode = null;
            //判断值是否超9
            if(val > 9){
                resultNode = new ListNode(val%10);
                //标记
                temp = 1;
            }else {
                resultNode = new ListNode(val);
                temp = 0;
            }
            //指向下一个指针
            p = p.next;
            q = q.next;
            //如果指针为空
            if (head == null){
                head = resultNode;
                lastNode = head;
                //跳出本次循环
                continue;
            }
            lastNode.next = resultNode;
            lastNode = lastNode.next;
        }
        //将剩余的位数拼接
        while(p != null){
            int val = p.val + temp;
            if(val > 9){
                lastNode.next = new ListNode(val % 10);
                temp = 1;
            }else{
                lastNode.next = new ListNode(val);
                temp = 0;
            }
            lastNode = lastNode.next;
            p = p.next;
        }
         while (q != null){
             int val = q.val + temp;
             if(val > 9){
                 lastNode.next = new ListNode(val % 10);
                 temp = 1;
             }else {
                 lastNode.next = new ListNode(val);
                 temp = 0;
             }
             lastNode = lastNode.next;
             q = q.next;
         }
         if(temp == 1){
             lastNode.next = new ListNode(temp);
             lastNode = lastNode.next;
         }
        return  head;
    }

