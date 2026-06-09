    我没有高屋建瓴的解题思想，这道题的思路对我来说也比较直接，就是找两个点，操作指针达到目的，下面简单记录一下思路。

    此题看似不复杂，但是还是比较容易出现错误的。主要是该题除了找到考察节点的 前一个节点之外(这里看作第0个)，还需
考虑后面连续两个节点(分别称作第1个，第2个)， 对这两个节点做倒装。倒装的前为了顾及循环的继续，还需要保存第三个节点
(第3个)。在交换的时候，需要注意交换的顺序，否则很容易出现错误。
    
    交换的大致顺序是这样的：

    1. 先将第2个节点指回第1个
    2. 然后将第1个节点的next指向第3个
    3. 最后将第0个的next指向第2个
    
    这样就实现了0->2->1->3的操作，继续考察第3个和第 4个的交换，和前面同样的道理。注意为了想要考察第3个，需要将指针
从位置0移动到2，也就是跳过1，即执行cur = cur.next.next。

    下面是我按照这个思路实现的代码：
```
public ListNode swapPairs(ListNode head) {

        ListNode virtual = new ListNode(-1);
        virtual.next = head;
        ListNode cur = virtual;
        while(cur.next!=null){
            ListNode next = cur.next.next;
            if(next!=null){
                ListNode temp = next.next;  //temp指向下一次需要循环的节点
                next.next = cur.next;   //先将第二个节点指回前一个
                cur.next.next = temp;
                cur.next = next;
            }else{
                break;
            }
            cur = cur.next.next ;
        }
        return virtual.next;
    }
```
