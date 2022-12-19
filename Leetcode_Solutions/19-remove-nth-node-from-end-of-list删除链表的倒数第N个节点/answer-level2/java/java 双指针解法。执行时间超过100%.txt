通过两个指针同步前进来实现一遍扫描删除倒数第N个元素
都在代码注释中。
不会写题解的我。
```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode front = head;//存放前面的指针
        ListNode after = head;//存放后面的指针
        for(int i=0;i<n-1;++i){//后面的指针前进n步
            after = after.next;
        }
        if(after.next==null)//到底了。说明删除的是第一个元素，直接返回head.next就行了
            return head.next;
        after = after.next;//这里是为了让after再前进一步。目的是便于front进行删除倒数第N个元素，如果没有这一步，实现删除第N个元素会变得非常困难
        while(after.next!=null){
            front = front.next;
            after = after.next;
        }
        front.next = front.next.next;//删除第N个元素（front.next指向的就是倒数第N个元素。把他之后再后一个就完成了删除操作。
        return head;//返回头
    }
}
```
