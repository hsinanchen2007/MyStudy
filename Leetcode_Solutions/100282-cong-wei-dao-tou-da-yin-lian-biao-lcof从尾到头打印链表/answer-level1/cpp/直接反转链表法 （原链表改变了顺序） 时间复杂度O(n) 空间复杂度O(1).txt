### 解题思路
此处撰写解题思路
直接反转链表 时间复杂度O(n) 空间复杂度O(1)

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
#include <algorithm>

class Solution {
public:
    ListNode* reversePrint(ListNode* head) {
        // 直接反转链表法
        ListNode* EndNode = head->next;
        ListNode* NewHeadNode = head;
        head->next = nullptr;
        ListNode* TmpNode = nullptr;
        while(EndNode)
        {
            TmpNode = EndNode->next;
            EndNode->next = NewHeadNode;
            NewHeadNode = EndNode;
            EndNode = TmpNode;
        }

        while(NewHeadNode)
        {
            cout << NewHeadNode->val << " - " ;
            NewHeadNode = NewHeadNode->next;
        }

        return NewHeadNode;

    }

    
};
```