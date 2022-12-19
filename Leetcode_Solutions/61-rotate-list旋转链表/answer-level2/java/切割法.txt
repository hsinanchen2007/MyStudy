```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        //计数
        int count = 0;
        ListNode temp = head;
        while (temp!=null){
            count++;
            temp = temp.next;
        }
        //如果刚刚好倍数或者count为1 则旋转之后为原来的样子
        //直接返回
        if (k%count==0 ||count==1) return head;
        //计算切割点
        int quy =count - k%count;
        temp = head;
        while (quy != 1){
            temp = temp.next;
            quy--;
            
        }
        //拿到链表头
        ListNode second = temp.next;
        //将上一段链表尾部next设为null，说明这是新的尾部了
        temp.next = null;
        //找到第二段链表尾部next指向head，连接起来就是旋转之后的链表了
        temp = second;
        while (temp.next != null){
            temp = temp.next;
        }
        temp.next = head;
        //返回链表头
        return second;
    }
}
```
