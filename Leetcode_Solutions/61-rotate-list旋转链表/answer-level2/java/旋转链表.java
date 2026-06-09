
![image.png](https://pic.leetcode-cn.com/a3897926c6bbcd77093a967a85dbd74844c80b69eb3439201c411c7d23c73729-image.png)


    public static ListNode rotate(ListNode head, int k){
            // 健壮性判断
            if (head == null) {
                return null;
            }
            if (k == 0){
                return head;
            }
            ListNode newHead = head;

            // 求列表长度
            int len = 0;
            while( newHead!= null){
                len++;
                newHead = newHead.next;
            }
            if (k % len == 0){
                return head;
            }

            // 将newhead指向后面一部链表
            int step = len - (k % len);
            ListNode preHead = null;
            newHead = head;
            if (step > 0) {
                while (step > 0) {
                    preHead = newHead;
                    newHead = newHead.next;
                    step--;
                }
            }else{
                return null;
            }
            preHead.next = null;

            // 将两部分拼接起来
            ListNode temp = newHead;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = head;

            return newHead;
        }

