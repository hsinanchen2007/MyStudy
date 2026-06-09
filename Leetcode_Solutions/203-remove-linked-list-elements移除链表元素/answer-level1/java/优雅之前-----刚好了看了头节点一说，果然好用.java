注意两点：1、找到对应值点的前驱，（当然两次遍历可以，但我提前记录下来，等于是用空间换时间）；
         2、利用哨兵（帮助类，辅助函数，辅助线类似的东西）统一删除代码写法，（删除特殊点时虚特殊处理，如最后一个节点刚好是要删除节点）；


```
    public ListNode removeElements(ListNode head, int val) {
    ListNode temp = new ListNode(0);
        temp.next = head;
    ListNode tempPro = temp;
        while(head!=null){
            
            if(head.val==val){
               head = head.next;
               tempPro.next = tempPro.next.next; 
            }else{
               head = head.next;
               tempPro = tempPro.next;
            }
            
        }
    return temp.next;
    }
```
