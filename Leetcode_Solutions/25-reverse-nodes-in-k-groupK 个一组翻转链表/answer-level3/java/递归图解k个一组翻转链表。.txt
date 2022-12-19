![1.JPG](https://pic.leetcode-cn.com/5641e03b922bef8b6f191565d08a3d9d8f4cf5dadd5e41371364f5d58633ae35-1.JPG)



代码如下:
ListNode reverseKGroup(ListNode head, int k) {
            ListNode curr=head;
            int count=0;//计数到k
            //指针指向第1个k的第一个节点，并以k给节点为一组取，直到凑不成一组。
            while(curr!=null&&count<k-1){
                curr=curr.next;
                count++;
            }
            //但凑不齐一组时，返回head节点
            if(curr==null){
                return head;
            }

            ListNode tmp=head;//保存head，翻转后head为链末尾，head.next可以链接未翻转的链表reverseKGroup(curr,k);
            ListNode pre=null;
            int num=k;
            //开始以k为一组进行翻转
            while(num>0){
                ListNode next=head.next;
                head.next=pre;
                pre=head;
                head=next;
                num--;
            }

            tmp.next=reverseKGroup(head,k);//head为未翻转链表开头。  !!!回溯后从后往前链接起来，21435中，3连5，然后继续回溯1连4，返回pre链表21435
            return pre;
        }