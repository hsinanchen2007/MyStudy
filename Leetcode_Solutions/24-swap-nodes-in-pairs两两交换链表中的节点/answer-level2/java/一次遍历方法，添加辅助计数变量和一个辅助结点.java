第一次写题解，没什么结构，大家将就看看。
思路如下：
    1.创建一个辅助头结点用于存取新链表和一个变量i，表示当前遍历的节点数
    2.i为奇数时说明需要交换，偶数时则跳过
代码如下
```public ListNode swapPairs(ListNode head) {
        ListNode ans = new ListNode(-1);
        ListNode nodeA = ans, node1 = head,node2;
        int i = 1;//便于计数
        while(node1!=null && node1.next!=null){
            //完成交换过程
            if(i%2==1){
                node2 = node1.next;
                nodeA.next = node2;
                node1.next = node2.next;
                node2.next = node1;
                nodeA = node1;
            }
            //遍历下一个节点
            else
                node1 = node1.next;
            i++;
        }
        //解决节点数目为奇数或者偶数的问题
        nodeA.next = i % 2 == 0? null : node1;
        return ans.next;
    }``


思路很简单，如果还是看不懂，分别调试一下奇数个节点和偶数个节点链表，观察引用变化情况，就很容易理解了!




