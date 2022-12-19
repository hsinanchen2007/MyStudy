每K个翻转一下, 我们实际上是做了两件事情:
- 翻转从head开始的K个
- 拼接 每次翻转之后的结果

那么为了完成第二步的拼接, 我们需要从第一步得到什么? 这里虽然是考虑需要从第一步得到什么, 实际上是要想清楚第二步是怎么拼接的.

我们假设, 每组都翻转了, 得到了各个head即:

head1'  head2'  head3' ...

问题来了, 只有head拼接不起来.

那么 head1'(head_next1) head2'(head_next2) head3'(head_next3) ....

其中每一个head{i+1}' 都是从head_next{i}翻转之后得来的. 

那么也就是说, 我们每次翻转的时候需要返回翻转之后的head' 以及下一次需要翻转的head_next
如何连起来: 上一次即将进行翻转的head_next(因为上一次即将翻转的head_next会变成尾结点) 的next指向这一次翻转之后的head'

需要注意:
1. 每次进行翻转的时候, head的next一定得复制成空指针
2. 最后一组, 如果个数小于k, 那么还得再翻转回去

```c++
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *latest_head = new ListNode(0);
        ListNode *ret = latest_head;
        ListNode *current_head = head;
        while (current_head != nullptr) {
            tuple<ListNode *, ListNode *> tup = this->reverseK(current_head, k);
            auto tmp = get<0>(tup);
            latest_head->next = tmp;
            latest_head = current_head;
            current_head = get<1>(tup);
        }
        return ret->next;
    }

    tuple<ListNode *, ListNode *> reverseK(ListNode *head, int k) {
        int i = 1;
        ListNode *head_next = nullptr;
        if (head != nullptr) {
            head_next = head->next;
            head->next = nullptr;  // 这里一定需要注意
        }

        while (head_next != nullptr && i < k) {
            ListNode *pre = head;
            ListNode *head_next_next = head_next->next;
            head = head_next;
            head->next = pre;
            head_next = head_next_next;
            i += 1;
        }
        if (i != k) {
            head = get<0>(this->reverseK(head, i));
            head_next = nullptr;
        }
        return {head, head_next};
    }
};
```