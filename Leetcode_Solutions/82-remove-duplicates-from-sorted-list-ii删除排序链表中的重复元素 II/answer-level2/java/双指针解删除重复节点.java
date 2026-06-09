1. 此题与83题的区别
     - 83题要求删除重复的节点，但是保存重复节点中的一个
     - 此题对重复节点进行全部删除
     - 因此可以借鉴下，采用双指针（快慢指针）但是快慢指针的概念上可能稍有区别


1. 为了方便 输出最终的删除的链表可以定义一个虚拟 指针指向链表的头部`  ListNode virtual = new ListNode(-1);virtual.next=head;`
2. 定义`pre`指针指向已经处理过链表的尾部，`ListNode pre = virtual;`
3. 定义`cur`指针指向尚未进行处理链表的第一个元素，` ListNode cur = head;`
4. 通过cur遍历整个链表，若发现重复元素则不断移动`cur`，直到`cur`走到这个重复元素的尾部。将`pre`指向`cur.next`即可
![image.png](https://pic.leetcode-cn.com/a8353f03cc85195ef97e3bda8eac68bb0aa97c74948f9cd45e84e9b9a89518f2-image.png)


```
 //将重复的元素全部删除
    public ListNode deleteDuplicates(ListNode head) {

        if(head==null||head.next==null) return head;

        //虚指针:定义虚指针很有必要，尤其当需要删除head的时候
        ListNode virtual = new ListNode(-1);
        virtual.next=head;

        //定义指针，pre是遍历前不用删除的第一个元素
        ListNode pre = virtual;

        //quick是正在遍历进行判断第一个元素
        ListNode quick = head;

        while(quick!=null){

            //发现相等则不断的移动的next直到移动到
            if(quick.next!=null&&quick.next.val==quick.val) {
                //不断移动指针直到
                while (quick.next != null && quick.next.val == quick.val) {
                    quick = quick.next;
                }
                //进行删除
                quick = quick.next;
                //此时pre不能动，
                pre.next = quick;

            }else{//不相等的话，则移动pre指针域quick指针
                pre=pre.next;
                quick=quick.next;
            }

        }
        //这里就体现了虚拟指针的好处啦
        return virtual.next;
    }
```
