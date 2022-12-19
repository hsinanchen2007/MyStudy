# 解题思路：递归：参考[@lyl0724-2](/u/lyl0724-2/)作者的文章[https://lyl0724.github.io/2020/01/25/1/](三套题解决递归问题)

递归的三部曲：
1 找终止条件：本题终止条件很明显，当递归到链表为空或者链表只剩一个元素的时候，没得交换了，自然就终止了。
2 找返回值：返回给上一层递归的值应该是已经交换完成后的子链表。
3 单次的过程：因为递归是重复做一样的事情，所以从宏观上考虑，只用考虑某一步是怎么完成的。我们假设待交换的俩节点分别为head和next，next的应该接受上一级返回的子链表(参考第2步)。就相当于是一个含三个节点的链表交换前两个节点，就很简单了。


```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* pnext=head->next;
        head->next=swapPairs(pnext->next);
        pnext->next=head;
        return pnext;
    }
};
```
