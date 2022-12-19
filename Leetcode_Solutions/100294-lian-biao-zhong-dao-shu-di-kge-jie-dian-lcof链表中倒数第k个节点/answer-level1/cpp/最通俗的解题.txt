### 解题思路
倒数第K个位置，为n-k+1的位置上。先确定n的个数，然后判断K是否是有效结点。最后再找到倒数k的位置

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
    int n=0;
    for(auto p=head;p;p=p->next)n++;
    if(k>n)return NULL;
    auto p=head;
    for(int i=0;i<n-k;i++)p=p->next;
    return p;
    }
};
```