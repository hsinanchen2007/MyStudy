 1. 遍历链表，求链表的长length
 2. 将ListNode[k]分成两部分，即 0到num2-1(num2= length%k)部分,添加的链表长度为num+1（length/k）
 3. 第二部分num2到k-1,添加的链表长度为num;num = 0,添加的为null;
 4. cut(ListNode left, int i) 将链表 left 切掉前 i 个节点，并返回后半部分的链表头

 public ListNode[] splitListToParts(ListNode root, int k) {

        ListNode[] listNodes = new ListNode[k];
        int length=0;
        ListNode p = root;
        while (p!=null){
            p=p.next;
            length++;
        }


        int num = length/k;
        int num2= length%k;
        int i=0;
        ListNode left = root;
        ListNode listNode;
<!-- 第一部分 listNodes[i] = listNode;listNode包含num+1个链表的节点-->
        for (;i<num2;i++){
            listNode =left;
            left = cut(left,num+1);
             listNodes[i] = listNode;

        }
<!-- 第一部分 listNodes[i] = listNode;listNode包含num个链表的节点,若num == 0,也可直接返回-->
            <!-- if(num==0){
               return listNodes;
            } -->
        for (;i<k;i++){
            listNode =left;
            left = cut(left,num);
            listNodes[i] = listNode;
        }
        return listNodes;

    }
<!-- 将链表 left 切掉前 i 个节点，并返回后半部分的链表头。 -->
    private ListNode cut(ListNode left, int i) {
        if (i==0)
            return null;
        ListNode cur = left;
        while (i-->1){
            cur = cur.next;
        }
        ListNode con = cur.next;
        cur.next = null;
        return con;
    }