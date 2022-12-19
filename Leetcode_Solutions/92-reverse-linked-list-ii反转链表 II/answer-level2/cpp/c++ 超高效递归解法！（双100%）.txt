如果没有掌握技巧，略难看懂，但是通过阅读大神的解析，很好的理解并运用了。
https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/
写了c++版本的，意外的效果超级棒！
![TIM图片20200330214047.png](https://pic.leetcode-cn.com/680ed535d11abdc46b835f1328bf15ba43f4efe7ef25b08ed287fdb5e546a231-TIM%E5%9B%BE%E7%89%8720200330214047.png)

```
class Solution {
public:
    ListNode* behind=NULL;//后继节点
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==1)return reverseL(head,n);//如果m为1，那么就是反转前n个链表的解法
        head->next=reverseBetween(head->next,m-1,n-1);
        return head;
    }

    ListNode* reverseL(ListNode* head,int L)//反转前L个链表
    {
        if(L==1)
        {
            behind=head->next;
            return head;
        }
        ListNode* last=reverseL(head->next,L-1);
        head->next->next=head;
        head->next=behind;
        return last;
    }
};
```

