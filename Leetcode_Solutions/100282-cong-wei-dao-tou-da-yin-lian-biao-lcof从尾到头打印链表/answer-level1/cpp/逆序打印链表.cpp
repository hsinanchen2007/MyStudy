### 解题思路
 法一 遍历+翻转reverse 
 法二 利用递归逆序

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
        vector<int> v;
        // 法一
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
        // 法二
        // reverseLink(head, v);
        // return v;

    }

    void reverseLink(ListNode* node, vector<int>& res) {
        if(node == NULL) return;
        reverseLink(node->next, res);
        res.push_back(node->val);
    }
};
```