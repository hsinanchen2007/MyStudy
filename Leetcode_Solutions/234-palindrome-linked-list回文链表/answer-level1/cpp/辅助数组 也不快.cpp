### 解题思路
执行用时 :
24 ms
, 在所有 C++ 提交中击败了
70.26%
的用户
内存消耗 :
16.1 MB
, 在所有 C++ 提交中击败了
5.01%
的用户

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
        if(head == NULL || head->next == NULL) return true;
        ListNode* cur = head;
        vector<int> list;
        while(cur != NULL){
            list.push_back(cur->val);
            cur = cur->next;
        }
        int n = list.size();
        for(int i = 0; i < (n>>1); i++){
            if(list[i] != list[n-i-1]) return false;
        }
        return true;
    }
};
```