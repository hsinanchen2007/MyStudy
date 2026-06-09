# 删除链表的倒数第k个结点：
思路同题目：**链表中倒数第k个结点**类似。
**采用快慢指针法**
第一步：让快指针先走k步,为了解决链表中只有一个元素，而且删除这个元素的特殊情况，需要进行判断。
第二步：俩个指针一起走，当fast->next为空的时候，slow指向倒数第k-1个结点。
第三步：让slow的next指向它的下下个结点（把倒数第k-1个结点和倒数第k+1个结点链接起来），此时删除完成。
这道题很巧妙地让想删除节点成为了slow的下一个结点（pos位置后的结点）我们在单链表中掌握比较好。
题目：**删除链表中的结点**，给了一种很棒的删除pos位置结点的方法，建议小伙伴们都去做一下。
```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
       struct ListNode* fast=head;
       struct ListNode* slow=head;
       //让fast指针先走n步
       while(n--)
       {
           if(fast->next)
            fast=fast->next;
           else
            return head->next;
       }
       //俩个指针一起走
       while(fast->next)
       {
           fast=fast->next;
           slow=slow->next;
       }
       //此时slow指向倒数第n-1个结点
       slow->next=slow->next->next;
       return head;
}
```
