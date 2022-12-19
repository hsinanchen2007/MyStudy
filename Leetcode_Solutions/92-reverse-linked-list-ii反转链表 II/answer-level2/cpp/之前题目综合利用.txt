### 解题思路
之前题目综合利用

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *work = head;
        ListNode *pre = dummy;
        int index = 1;
        for(;index < m;++index)
        {
            work = work->next;
            pre = pre->next;
        }
        ListNode *l = nullptr;
        ListNode *tmp = work;

        pre->next = reverse(work,index,n,l);

        work->next = l;
        return dummy->next;

    }


    ListNode *reverse(ListNode *work,int &index,int &n,ListNode * &last)
    {
        if(index == n)
        {
            last = work->next;
            return work;
        }
        ListNode *p = reverse(work->next,++index,n,last);
        work->next->next = work;
        work->next = nullptr;
        return p;

    }
};
```