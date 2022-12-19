就是最笨的if语句来判断...

```java []
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode Head1 = new ListNode(0);   //返回链表
        ListNode Head =  Head1;   //头结点
        boolean jinwei = false;   //进位标志
        int sum=0;  //位计算结果
        while(l1 != null || l2!= null || jinwei == true){
            int a = (l1 != null) ? l1.val : 0;
            int b = (l2 != null) ? l2.val : 0;
            if (jinwei == false){
                if (a+b>=10){
                    sum = a+b-10;
                    jinwei = true;
                }
                else sum = a+b;
            }
            else{
                if (a+b+1>=10){
                    sum = a+b+1-10;
                    jinwei = true;
                }
                else{
                    sum = a+b+1;
                    jinwei = false;
                }
            }
            Head.next = new ListNode(sum);
            Head = Head.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return Head1.next;
    }
}
```
