### 解题思路
此处撰写解题思路

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
    vector<int> v;
    vector<int> reversePrint(ListNode* head) {
        if(head==NULL)return v;
        else{
            reversePrint(head->next);
            v.push_back(head->val);
        }
        return v;
    }
};
```