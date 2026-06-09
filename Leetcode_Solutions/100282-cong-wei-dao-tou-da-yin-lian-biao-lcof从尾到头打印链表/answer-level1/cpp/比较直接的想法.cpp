### 解题思路
在c++中，利用vector的insert函数实现就可以了。

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
        vector<int> s;
        while(head!=NULL){
            s.insert(s.begin(), head->val);
            head=head->next;
        }
        return s;
    }
};
```