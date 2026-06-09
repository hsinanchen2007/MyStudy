该思路来自于反转链表 II官方题解[反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/fan-zhuan-lian-biao-ii-by-leetcode/)
使用递归反转链表的思路来源于反转字符串时使用的类似方法。反转字符串的一个巨大优势是可以使用下标信息。我们可以创建两个指针，一个开头，一个结尾。不断地处理这两个指针，并将两个指针向中间移动。看完了官方题解,再稍微修改一下就是我们的方法。
这道题的解法比起反转链表来说较简单，因为它刚开始left指针默认是指向开头,不必移动。通过递归，先找到尾结点，并完成反转，结束后将left指针指向left.next,再返回到上一层(每一层都有一个right指针，而所有层共用一个left指针)
```java
class Solution{
    private ListNode left;
    private boolean stop;   
    public void reorderList(ListNode head) {
        left = head;
        stop = false;
        orderList(head);
    }

    //该方法作用是在指定条件下完成left指针和right指针的连接任务
    public void orderList(ListNode right){
        if(right == null) return;
        orderList(right.next);
        if(this.left == right || right.next == this.left){ //最后两指针相遇或错过时，left指针都指向尾结点
            left.next = null;   //防止出现环
            this.stop = true;   //stop为真时不做处理
        }

        if(!this.stop){
            ListNode succ = this.left.next;
            right.next = succ;
            this.left.next = right;
            this.left = succ;
        }
    }
}
```

