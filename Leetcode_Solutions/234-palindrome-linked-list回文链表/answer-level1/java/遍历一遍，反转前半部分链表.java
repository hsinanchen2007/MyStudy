```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null){
            return true;
        }
        ListNode node = head;
        ListNode fastNode = head;
        ListNode last = null;
        ListNode next = null;
        while(fastNode.next !=null && fastNode.next.next != null){
            fastNode = fastNode.next.next;
            //反转前半部分
            next = node.next;
            node.next = last;
            last = node;
            node = next;
        }
        //结束循环后情况：
        //长度为奇数：node 指向中间节点，last 指向中间前面的一个节点
        //长度为偶数：node 指向第 n/2 个节点，last 指向第 n/2 - 1 个节点

        ListNode pre,after;
        if(fastNode.next != null){
            //长度为偶数，从node往前、node+1往后开始比较
            after = node.next;
            node.next = last;
            pre = node;
        }else{
            //长度为奇数，从node-1往前、node+1往后开始比较
            pre = last;
            after = node.next;
        }
        while(pre!=null && after!=null){ //对比两个链表是否相等即可
            if(pre.val != after.val){
                return false;
            }
            pre = pre.next;
            after = after.next;
        }
        return true;
    }
}
```
