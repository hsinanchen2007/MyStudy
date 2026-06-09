### 解题思路
先找到最后一个节点定为ret，head表示它的前一个 head->next->next=head,head->next=null
有点迷惑……

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
//用递归的方法
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* ret=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return ret;
    }
};
```