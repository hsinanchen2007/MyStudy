记录高赞答案的思路。核心还是比较，然后改变指针域的指向
```
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(-1);//设置一个头结点
        ListNode pre = dummy;//准备一个可以移动的结点，常规操作
        dummy.next = head;//把这个头结点和当前链表第一个结点连起来
        while(head!=null&&head.next!=null){//开始循环查找,因为用到head.next，所以必须保证不为空
            if(head.val<head.next.val){//如果是排好序的，不用管
                head = head.next;//查找下一个结点
                continue;//
            }
            pre = dummy;//如果顺序不对，每次都从第一个结点开始向后找插入位置
            while(pre.next.val<head.next.val){//如果没有找到，就一直往后找
                pre = pre.next;//下一个结点
            }//循环退出，说明找到了
            //拿走head.next。相当于删除了这个结点，然后把他插入pre.next的前面a
            ListNode curr = head.next;//保存这个结点
            head.next = curr.next;//让head后续指向下下个结点。此时这个结点被断开了。
            curr.next = pre.next;//插到pre.next的前面，所以pre指向它的后续节点
            pre.next =curr;//即把pre的后续指向这个head.next;
        }
        return dummy.next;//返回头结点的后续
    }
}
```
