
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        vector<int> help;
        while(head!=NULL)
        {
            help.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<help.size()/2;i++)
            if(help[i]!=help[help.size()-1-i]) return false;
        return true;
    }
};
```