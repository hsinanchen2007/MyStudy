### 解题思路
设立一个快一个慢指针，在环里相遇证明有环；
注意要判断next==nullptr，否则容易报错

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
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return false;
        
        ListNode* m=head;//一次移动一个
        ListNode* k=head;//一次移动两个
        while(m!=nullptr && m->next!=nullptr && k!=nullptr&& k->next!=nullptr && k->next->next!=nullptr)//注意判断不为nullptr否则会报错
        {
            m=m->next;
            k=k->next->next;
            if(m==k)//相等
            {
                return true;
            }
        }
        return false;

        
    }
};
```