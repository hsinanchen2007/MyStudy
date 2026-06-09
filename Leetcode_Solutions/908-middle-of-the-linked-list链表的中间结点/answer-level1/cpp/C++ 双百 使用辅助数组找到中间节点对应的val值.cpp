### 解题思路
注意一点：要先拷贝一份head以存储节点的val值，原head来用于找中间节点。

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
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) return head;
        if(head->next->next==nullptr) return head->next;
        ListNode* copyhead = head;
        vector<int> arr;
        while(copyhead!=nullptr)
        {
            arr.push_back(copyhead->val);
            copyhead = copyhead -> next;
        }       
        int a = (arr.size()/2)+1;
        ListNode* resnode;
        while(a!=0)
        {
            resnode = head;
            head = head -> next;
            --a;
        }
        return resnode; 
    }
};
```