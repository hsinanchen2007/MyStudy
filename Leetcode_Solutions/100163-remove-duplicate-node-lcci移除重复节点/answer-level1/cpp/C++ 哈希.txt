### 解题思路
利用哈希表存放已经遍历节点的出现频次，若下一节点已经出现过，就删除。

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* r=head;
        if(!head)return NULL;
        unordered_map<int,int>mp;
        mp[r->val]++;
        while(r&&r->next){
            while(r->next&&mp[r->next->val]>0){
                r->next=r->next->next;
            }
            if(r->next){
                mp[r->next->val]++;
                r=r->next;
            }
               
        }
        return head;
    }
};
```