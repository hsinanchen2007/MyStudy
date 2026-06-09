### 解题思路
反转的意思，可以理解为在第一遍扫描时反向插入，
这样可以考虑使用vector.insert(vector.begin(),val),每次都在首部插入。
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
        vector<int> result;
        //if(head == NULL) return result; 
        while(head)
        {
            result.insert(result.begin(),head->val);
            head = head->next;
        }
        return result;
    }
};
```