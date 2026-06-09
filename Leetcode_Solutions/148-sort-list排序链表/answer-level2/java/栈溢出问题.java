这个题的关键是断链，扫了一圈答案，都没有出现栈溢出的吗，大家都太聪明了吧。

我刚开始用快慢指针做有出现死循环的情况：

fast=head,slow=head;
while(fast!=null&&fast.next!=null){
    fast=fast.next.next;
    slow=slow.next;
}
//断链
ListNode temp=slow.next;
slow.next=null;
于是从slow处断开了
head...slow->null    temp...fast->null

考虑只有两个节点的情况
![image.png](https://pic.leetcode-cn.com/e5c597a61259f520c95a070f79e0f9dddd7e0e9ef80e12926c5c2e48793decf9-image.png)
所以这样不可以，不能让temp指向null
否则就会死循环导致栈溢出

解决的办法就是让fast先走一步，保证slow和fast之间是有元素的，不会出现slow的下一个就是fast，而fast指空的情况。

即
fast=head.next,slow=head;
while(fast!=null&&fast.next!=null){
    fast=fast.next.next;
    slow=slow.next;
}
然后再断链必然不会死循环了。

代码