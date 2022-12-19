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
    bool isPalindrome(ListNode* head) 
    {
        string temp = "";
        while(head != nullptr)
        {
            temp += ('0' + head->val);
            head = head->next;
        }
        string res = temp;
        reverse(temp.begin(), temp.end());
        return temp == res;
    }
};
```