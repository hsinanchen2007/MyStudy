### 解题思路
1、先计算链表长度n，我们发现旋转n之后和原来的链表是相同的，所以取m=k%n
2、每次把最后一个放在首位，把最后一个删除，重复m次即可
但是我的方法效率不高，还是一次性放齐了比较好

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0) return head;
        ListNode* res=head;
        int n=0;//链表长度
        while(head!=nullptr)
        {n++;head=head->next;}
        int m=k%n;
        for(int i=1;i<=m;++i)
        {
            res=hanshu(res);
        }
        return res;
        
    }
    //写一个函数
    ListNode* hanshu(ListNode* head)
    {
        ListNode* p=head;
        ListNode* h=head;
        if(head->next==nullptr)
            return head;
        if(head->next->next==nullptr)
        {
            int c=head->val;
            head->val=head->next->val;
            head->next->val=c;
            return head;
        }
        while(p!=nullptr&&p->next!=nullptr)
        {
            p=p->next;
        }
        while(h!=nullptr&&h->next!=nullptr&&h->next->next!=nullptr)
        {
            h=h->next;
        }
        h->next=nullptr;
        p->next=head;
        return p;

    }
};
```