### 解题思路
此处撰写解题思路：妙用初始化 vector<ListNode*> v(k,nullptr);耗时击败100%的用户
![2020-01-07_224300.png](https://pic.leetcode-cn.com/b04cda85ad098d824efa1c5119ae90db419320145805c26d52c936284381bb33-2020-01-07_224300.png)
需要遍历两次链表---》vector<ListNode*> v(k,nullptr);初始化妙用，分隔后为空的子链表无需理会
耗时击败100%的用户
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *fast=root;
        int len=0;
        while(fast)
        {
            len++;
            fast=fast->next;
        }
        int pn=len%k;
        vector<ListNode*> v(k,nullptr);//k个链表，初始化都赋值为nullptr，故只需遍历两次链表即可，分隔的链表中为空的话，则无需理会。
        k=len/k;//每组至少有多少个，k=1时需考虑pn>0的情况
        ListNode *tail=nullptr,*p=nullptr;
        fast=root;
        int n=0;
        int i=0;//记录v的下标
        while(fast)
        {
            n++;
            p=fast->next;
            if(n==1)
            {
                v[i]=fast;
                tail=fast;
                if(k<=1)//k=0,k=1
                {
                    if(k&&pn&&i+1<=pn)
                    {//k=1,len>k,有些子链表多一个肯定不为空结点，不用判断p==NULL
                        tail->next=p;
                        tail=p;
                        p=p->next;
                    }
                    tail->next=nullptr;
                    i++;
                    n=0;
                }
            }
            else if(n==k)
            {
                tail->next=fast;
                tail=fast;
                if(pn&&i+1<=pn)
                {
                    tail->next=p;
                    tail=p;
                    p=p->next;
                }
                tail->next=nullptr;
                i++;
                n=0;
            }
            else//tail肯定不为空
            {
                tail->next=fast;
                tail=fast;
            }
            fast=p;
        }
        return v;
    }
};
```