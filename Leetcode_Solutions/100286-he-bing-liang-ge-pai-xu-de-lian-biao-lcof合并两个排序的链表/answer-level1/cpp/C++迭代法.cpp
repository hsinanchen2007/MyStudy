### 解题思路
注意两点：1、sum不能为空指针 要初始化
2、sum->next=l1;不能写sum=l1 要不无法连成
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
        if(l1==nullptr&&l2==nullptr) return nullptr;
        ListNode* sum=new ListNode(0);//不可以写成nullptr！new LiseNode(0)意为初始化
        ListNode* ret=sum;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<l2->val)
            {
                sum->next=l1;//注意！此处写sum->next
                l1=l1->next;
            }
            else 
            {
                sum->next=l2;
                l2=l2->next;   
            }
            sum=sum->next;
        }
        //如果有一个链空了
        while(l1!=nullptr)
        {
            sum->next=l1;
            sum=sum->next;
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            sum->next=l2;
            l2=l2->next;
            sum=sum->next;
        }
        return ret->next;


    }
};
```