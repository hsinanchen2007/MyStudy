### 本题思路：
    循环遍历链表节点，将待删除节点的前一个节点直接指向待删除节点的后一个节点即可

#### 需要注意的问题：
    头节点没有前一个节点，需要特别处理

#### 方法一：
    先处理头节点，再处理后面的的节点
```
    public ListNode removeElements(ListNode head, int val) {
        while (head != null && head.val == val) {
            head = head.next;
        }
        //处理链表元素都为待删除元素的情况
        if (head == null) {
            return null;
        }

        ListNode prev = head;
        while (prev.next != null) {
            if(prev.next.val == val){
                prev.next = prev.next.next;
            }else{
                prev = prev.next;
            }
        }
        return head;
    }
```

#### 方法二：设立虚拟头节点，使链表中的每一个节点都有前一个节点，可以统一处理
```
    public ListNode removeElements(ListNode head, int val) {
        //虚拟头节点的值用不到，随意赋值
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        while(prev.next != null){
            if(prev.next.val == val){
                prev.next = prev.next.next;
            }else{
                prev = prev.next;
            }
        }
        return dummyHead.next;
    }
```
