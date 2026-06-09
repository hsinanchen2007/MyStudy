### 解题思路
用递归写的话代码非常漂亮还简洁~~但有时候面试官抽风不让用递归...
不用额外空间，单纯改变指针方向实现合并
下面是比较直白的思路
先找头结点小的一条链，最后结果就返回这条链的头结点，把另一条链往这条链上插就行了。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* p,*p1;
        bool flag=true;
        if(l1->val>l2->val)
        {
            p=l2;
            p1=l1;
            flag=false;
        }
        else
        {
            p=l1;
            p1=l2;
        }
        while(p1!=NULL)
        {
            if(p->next==NULL)
            {
                p->next = p1;
                break;
            }
            if(p1->val > p->next->val)
            {
                p=p->next;
            }
            else
            {
                ListNode* temp = p->next;
                p->next = p1;
                p1 = p1->next;
                p->next->next = temp;
                p=p->next;
                temp = NULL;
                delete temp;
            }
        }
        if(flag)
            return l1;
        else
            return l2;
    }
};
```