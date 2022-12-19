**运行结果**
执行用时 :4 ms, 在所有 java 提交中击败了97.39%的用户
内存消耗 :38.8 MB, 在所有 java 提交中击败了100.00%的用户
**思路：**
- 先生成一个带表头的链表，再利用三个指针进行操作
- h作为一个前继节点，方便进行删除操作
- p、q为两个前后指针，记录连续和为0的节点的起始位置
- p总从h的下一个开始移动，q总从p的下一个开始移动
- 当出现sum(p, q) = 0时，将p至q的节点进行删除，即h.next = q.next
- 注意：
      *当某次进行了删除操作后，p直接从h的后一个节点开始继续遍历，而不是先将h向后移动，否则无法处理1->2->3->-3->-2->1这样的情况，所以定义一个变量flag，对h指针是否后移进行控制*

**代码：**
```
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        //先处理特殊情况
        if(head.next == null){
            if(head.val == 0) return null;
            else return head;
        }
        //生成带头结点的链表
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode h = dummyHead;
        boolean flag = true;
        
        while(h.next != null){
            flag = true;     //要记得每一次循环都要将flag恢复默认值
            ListNode p = h.next;
            //当p节点为0时直接进行删除操作，同理删除操作后不需要进行h的后移，
            //但这里可以用continue语句代替flag的控制作用
            if(p.val == 0){
                h.next = p.next;
                continue;
            }
            ListNode q = p.next;
            int sum = p.val;    //sum是p至q的总和
            while(q != null){
                sum += q.val;
                //flag的控制作用体现在这里，要加上break使用
                if(sum == 0){
                    h.next = q.next;
                    flag = false;
                    break;
                }
                else q = q.next;
            }
            //flag控制
            if(flag) h = h.next;
        }
        return dummyHead.next;
    }
}
```
