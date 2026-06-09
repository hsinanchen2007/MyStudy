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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        vector<ListNode*> vec;
        ListNode* temp = head;
        while (temp) {
            vec.push_back(temp);
            temp = temp->next;
        }

        if (n > vec.size() || (n == 1 && vec.size() == 1)) {
            return NULL;
        }

        
        if (vec.size() - n + 1 == vec.size() ) {
            temp = vec[vec.size() - n - 1];
            temp->next = NULL;
        } else if (vec.size() - n == 0) {
            head = vec[vec.size() - n + 1];
        } else {
            temp = vec[vec.size() - n - 1];
            ListNode* post = vec[vec.size() - n + 1];
            temp->next = post;
        }

        return head;
    }
};
```