```java
/*
自底向上的归并; 最难的就是找出归并的目标, 每一次循环归并的链表的长度都不同, 如何找出它们?
主题循环中, curr必须赋值为dummy.next, 不能再用head了! 因为在归并的过程中, head可能会变
split()中涉及断链操作
*/
class Solution {
    public ListNode sortList(ListNode head) {
        if(head==null)
            return null;
        //创建临时节点
        ListNode dummy = new ListNode(0);
        //我老忘将dummy连向头结点
        dummy.next = head;
        //统计链表节点个数
        int n = 0;
        ListNode curr = head;
        while(curr!=null){
            n++;
            //upate
            curr =  curr.next;
        }
        //自底向上地归并; 细节:循环的更新条件:移位执行速度更快;  1v1, 2v2, 4v4, 8v8,...; i表示该次循环中子链表的长度; 循环变量i和split()方法配合使用, 找到子链表的头结点
        for(int i = 1; i < n; i <<= 1){
            ListNode pre = dummy;
            //细节: 这个地方必须写成dummy.next!!!!! 写成head就错了
            curr = dummy.next;
            while(curr!=null){
                //待归并的两个链表中靠左的链表头结点
                ListNode left = curr;
                //待归并的两个链表中靠右的链表头结点; 通过靠左链表的头结点和当前的子链表长度i就能找出靠右链表的头结点
                //split()会将子链表的尾节点指向null
                ListNode right = split(left, i);
                //找出下一段子链表的头结点
                curr = split(right, i);
                //归并两个子链表; 并返回归并后的链表的尾节点, 该尾结点将是下一段子链表头结点的前一个节点; 返回pre用在下一轮merge中, 像是自己更新自己
                pre = merge(left, right, pre);
            }
        }
        return dummy.next;
    }
    //根据当前子链表的头结点head和子链表长度linkedListLength, 找出下一段子链表的头结点
    public ListNode split(ListNode head, int linkedListLength){
        if(head==null)
            return null;
        //普通情况, 从head出发, 往后移动LinkedListLength就是下一段子链表的头结点, 不过中途可能会遇到null, 所以得格外留意
        //下面的for循环让head移动到当前子链表的尾节点, 不过如果当前子链表的长度不够linkedListLength的话, 那就有多长就返回当前长度下最后一个节点
        //这样循环的好处就是方便表示下一段子链表的头结点; 如果下一段子链表的头结点是null, 那么有可能是当前子链表长度不足linkedListLength导致,或者是恰好没有下一段子链表
        for(int i=1; head.next!=null && i<linkedListLength; i++){
            head = head.next;
        }
        //下一段子链表的头结点
        ListNode right = head.next;
        //细节:将当前子链表的尾结点指向null, 作为归并的循环终止条件
        head.next = null;
        //返回下一段子链表的头结点
        return right;
    }
    //归并过程; 基本上就是普通的归并两个有序链表的题目, 只多了两处: 1)需要传入一个pre,方便和已经归并好的链表连接; 2)返回归并后的链表的尾结点, 作为下一次归并过程的pre
    public ListNode merge(ListNode left, ListNode right, ListNode pre){
        ListNode curr = pre;
        while(left!=null && right!=null){
            if(left.val < right.val){
                curr.next = left; 
                left = left.next;
            }
            else{
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }
        //注意, 由于后面要找链表的最后一个节点, 所以此处的两个if不能合成一句话, 合成一句有可能让curr指向null, 导致后面的循环出错
        if(left!=null)
            curr.next = left;
        if(right!=null)
            curr.next = right;
        //找到归并后的链表的最后一个节点
        while(curr.next!=null)
            curr = curr.next;
        return curr;
    }
}
```