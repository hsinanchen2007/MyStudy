### 解题思路
存储到容器中

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
        vector<int> result;
        while(head != NULL){
            result.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<result.size();i++){
            if(result[i] != result[result.size()-1-i]){
                return false;
            }
        }
        return true;

    }
};
```