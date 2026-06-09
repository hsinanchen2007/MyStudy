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
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        if(head==NULL) 
            return nums;
        ListNode* p=head;
        while(p!=NULL){
            nums.push_back(p->val);
            p=p->next;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};
```